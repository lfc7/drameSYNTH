/* Drame-TeensySynth (TEENSY 3.6)

    midi synth trying to poorly mimic the polyVoks

    fit inside midi keyboard

*/

/** include external lib */
#include <Audio.h>
#include <MIDI.h>
#include  <Entropy.h>

/** local includes */
#include "midi_CC_patch.h"
#include "guiTool.h"

MIDI_CREATE_DEFAULT_INSTANCE();

const int WaveForm[8] = {
  WAVEFORM_SINE,
  WAVEFORM_SAWTOOTH,
  WAVEFORM_SAWTOOTH_REVERSE,
  WAVEFORM_SQUARE,
  WAVEFORM_TRIANGLE,
  WAVEFORM_PULSE,
  WAVEFORM_SAMPLE_HOLD,
  WAVEFORM_SQUARE
};

const uint8_t clockDividerArray[10] = {96, 64, 48, 32, 24, 16, 12, 8, 6, 1};

//some globals var
uint8_t vcoa_notes[3];
uint8_t vcob_note;
float vcob_octave;


bool  flag_vcf_lfo_amount = false;
bool  flag_vcf_lfo_freq = false;
bool  flag_vca_lfo_amount = false;
bool  flag_vca_lfo_freq = false;
bool  flag_delay_dry_lvl = false;
bool  flag_delay_time = false;

bool  flag_retrigg = false;
bool  flag_follow = false;
bool  flag_hold   = false;

bool  flagBank2 = false;


uint8_t max_tick = 48;
uint8_t tick_counter = 0;
uint8_t sync_counter = 0;
uint8_t clockOutLenght = 8;
unsigned long last_Tick_uS , clock_time_uS , last_clock_uS;
bool flag_beatClock = false;

/************ ROUTINES ****************/
float midi2freq(uint8_t midinote)
{
  /*
    float midi[127];
    int a = 440; // a is 440 hz...
    for (int x = 0; x < 127; ++x)
    {
    midi[x] = (a / 32) * (2 ^ ((x - 9) / 12));
    }
  */
  uint8_t rnd = Entropy.random(100);
  float tune = 440.0 + (rnd / 200);
  return ( tune / 32.0) * pow(2.0 , ( (midinote - 9.0) / 12.0) );
}

float midi2freqDetune( int  detune, uint8_t midinote)
{
  float tune =  440.0 * ( (float(detune) + 8192.0 ) / 8192.0) ;//+  (rnd / 300.0);
  return ( tune / 32.0) * pow(2.0 , ( (midinote - 9.0) / 12.0) );
}

void triggON()
{
  VCF_env.noteOn();
  VCA_env.noteOn();
}

void triggOFF()
{
  VCF_env.noteOff();
  VCA_env.noteOff();
}

/*
  void sort3(int *d)
  {
  int i, j;
  for (i = 1; i < 3; i++) {
    int tmp = d[i];
    for (j = i; j >= 1 && tmp > d[j - 1]; j--)
      d[j] = d[j - 1];
    d[j] = tmp;
  }
  }
*/

byte lowestMidiNote(uint8_t *d)
{
  byte res = d[0];
  if ( res > d[1])res = d[1];
  if ( res > d[2])res = d[2];
  return res;
}

void handleNoteOn(byte channel, byte midinote, byte velocity)
{

  float noteInHz;
  noteInHz = midi2freq(midinote);
  if (vcob_note == 128 && lowestMidiNote(vcoa_notes) > midinote)
  {
    vcob_note = midinote; //remind
    VCOB.frequency(noteInHz * vcob_octave);
    VCOB.amplitude(0.25);
    //VCO_ring.frequency(noteInHz * 2.0);

    //when only alone
    if (lowestMidiNote(vcoa_notes) == 128) // && vcoa_notes[1] == 128  && vcoa_notes[2] == 128)
    {
      VCOA1.frequency(noteInHz);
      VCOA1.amplitude(0.25);
    }

    triggON();

  }
  else
  {
    //search an empty space on vcos

    if (vcoa_notes[0] == 128)
    {
      vcoa_notes[0] = midinote;
      VCOA1.frequency(noteInHz);
      VCOA1.amplitude(0.25);

      if (flag_follow)VCF.frequency(noteInHz);
      if (flag_retrigg)triggON(); // retrigg <--------------
    }
    else if (vcoa_notes[1] == 128)
    {
      vcoa_notes[1] = midinote;
      VCOA2.frequency(noteInHz);
      VCOA2.amplitude(0.25);

      if (flag_follow)VCF.frequency(noteInHz);
      if (flag_retrigg)triggON(); // retrigg <--------------
    }
    else if (vcoa_notes[2] == 128)
    {
      vcoa_notes[2] = midinote;
      VCOA3.frequency(noteInHz);
      VCOA3.amplitude(0.25);

      if (flag_follow)VCF.frequency(noteInHz);
      if (flag_retrigg)triggON(); // retrigg <--------------

    }


  }


}

/**
  void handleNoteOn(byte channel, byte midinote, byte velocity)
  {

  float noteInHz;
  noteInHz = midi2freq(midinote);
  if (vcob_note == 128)
  {
    vcob_note = midinote; //remind
    VCOB.frequency(noteInHz * vcob_octave);
    VCOB.amplitude(0.25);
    //VCO_ring.frequency(noteInHz * 2.0);
    //when only alone
    if (vcoa_notes[0] == 128) // && vcoa_notes[1] == 128  && vcoa_notes[2] == 128)
    {
      VCOA1.frequency(noteInHz);
      VCOA1.amplitude(0.25);
    }
    if (flag_follow)VCF.frequency(noteInHz * vcob_octave);
    triggON();
  }
  else
  {
    //search an empty space on vcos
    if (vcoa_notes[0] == 128)
    {
      vcoa_notes[0] = midinote;
      VCOA1.frequency(noteInHz);
      VCOA1.amplitude(0.25);

      // mistake it never happen
     // if (vcob_note == 128)
     // {
     //   VCOB.frequency(noteInHz * vcob_octave);
     //   VCOB.amplitude(0.25);
     //   VCO_ring.frequency(noteInHz * 2.0);
    //    if (flag_follow)VCF.frequency(noteInHz * vcob_octave);
    //  }
      //

      if (flag_retrigg)triggON(); // retrigg <--------------
    }
    else if (vcoa_notes[1] == 128)
    {
      vcoa_notes[1] = midinote;
      VCOA2.frequency(noteInHz);
      VCOA2.amplitude(0.25);

      if (flag_retrigg)triggON(); // retrigg <--------------
    }
    else if (vcoa_notes[2] == 128)
    {
      vcoa_notes[2] = midinote;
      VCOA3.frequency(noteInHz);
      VCOA3.amplitude(0.25);
      if (flag_retrigg)triggON(); // retrigg <--------------

    }


  }

  }
*/

void handleNoteOff(byte channel, byte pitch, byte velocity)
{
  // Do something when the note is released.
  // Note that NoteOn messages with 0 velocity are interpreted as NoteOffs.

  //do nothing if flag_hold
  if (flag_hold)return;

  uint8_t lowestNote;
  lowestNote = lowestMidiNote(vcoa_notes);

  //search pitch on vco

  //VCO B
  if (vcob_note == pitch)
  {

    vcob_note = 128;

    // is there a VCO - A playing ?
    if ( lowestNote == 128 ) //no vcoA playing
      //if (vcoa_notes[0] == 128)
    {
      VCOB.amplitude(0);
      VCOA1.amplitude(0);
      VCOA2.amplitude(0);
      VCOA2.amplitude(0);
    } else {
      // folow the lowest
      VCOB.frequency(midi2freq(lowestNote) * vcob_octave);
      VCOB.amplitude(0.25);
      if (flag_follow)VCF.frequency(midi2freq(lowestNote));
    }
  }
  else
  {
    if (vcoa_notes[0] ==  pitch)
    {
      vcoa_notes[0] = 128;
      VCOA1.amplitude(0);
    }
    else if (vcoa_notes[1] == pitch)
    {
      vcoa_notes[1] = 128;
      VCOA2.amplitude(0);
    }
    else if (vcoa_notes[2] ==  pitch)
    {
      vcoa_notes[2] = 128;
      VCOA3.amplitude(0);
    }

    if (vcob_note == 128) //vcob is following
    {
      if ( lowestNote == pitch ) // and we remove this one
      {
        if ( lowestMidiNote(vcoa_notes) != 128)  // a vcoa is still playing
        {
          //folow new lowest
          VCOB.frequency(lowestMidiNote(vcoa_notes) * vcob_octave);
          VCOB.amplitude(0.25);
        }
        else
        {
          //was the last
          VCOB.amplitude(0);
        }
      }
    }
    else
    {
      //vcob is playing

      if (lowestMidiNote(vcoa_notes) == 128) //vcoa is not playing anymore
      {
        //follow B
        VCOA1.frequency(midi2freq(vcob_note));
        VCOA1.amplitude(0.25);
      }

    }


  }

  if (vcob_note == 128 && vcoa_notes[0] == 128 && vcoa_notes[1] == 128  && vcoa_notes[2] == 128)
  {
    triggOFF();
  }
}

/*
  void handleNoteOff(byte channel, byte pitch, byte velocity)
  {
  // Do something when the note is released.
  // Note that NoteOn messages with 0 velocity are interpreted as NoteOffs.

  //do nothing if flag_hold
  if (flag_hold)return;


  //search pitch on vco
  if (vcob_note == pitch)
  {
    vcob_note = 128;
    if (vcoa_notes[0] == 128)
    {
      VCOB.amplitude(0);
      VCOA1.amplitude(0);
    } else {
      VCOB.frequency(midi2freq(vcoa_notes[0])* vcob_octave);
      VCOB.amplitude(0.25);
      if (flag_follow)VCF.frequency(midi2freq(vcoa_notes[0]) * vcob_octave);
    }

    //if (vcoa_notes[0] == 128)VCOA1.amplitude(0);
  }
  else
  {
    if (vcoa_notes[0] ==  pitch)
    {
      vcoa_notes[0] = 128;
      if ( vcob_note != 128 )// && vcoa_notes[1] == 128  && vcoa_notes[2] == 128)
      {
        VCOA1.frequency(midi2freq(vcob_note));
        VCOA1.amplitude(0.25);
      }
      else
      {
        VCOA1.amplitude(0);
        if (vcob_note == 128)VCOB.amplitude(0);
      }
    }
    else if (vcoa_notes[1] == pitch)
    {
      vcoa_notes[1] = 128;
      VCOA2.amplitude(0);
    }
    else if (vcoa_notes[2] ==  pitch)
    {
      vcoa_notes[2] = 128;
      VCOA3.amplitude(0);
    }
  }


  if (vcob_note == 128 && vcoa_notes[0] == 128 && vcoa_notes[1] == 128  && vcoa_notes[2] == 128)
  {
    triggOFF();
  }
  }
*/
void handleControlChange(byte channel, byte number, byte value)
{

  if (flagBank2 && number >= 30 && number <= 38)number = number + 70;

  switch (number) {

    case MODULATION_WHEEL:
      if (flag_vcf_lfo_amount)handleControlChange(channel, VCF_LFO_AMOUNT_CC, value);
      if (flag_vcf_lfo_freq)handleControlChange(channel, VCF_LFO_FREQ_CC, value);
      if (flag_vca_lfo_amount)handleControlChange(channel, VCA_LFO_AMOUNT_CC, value);
      if (flag_vca_lfo_freq)handleControlChange(channel, VCA_LFO_FREQ_CC, value);
      if (flag_delay_dry_lvl)handleControlChange(channel, DELAY_DRY_LVL_CC, value);
      if (flag_delay_time)handleControlChange(channel, DELAY_TIME_CC, value);
      break;

    case CLOCK_IN_CC:
      if ( (( micros() - last_clock_uS ) / 48UL) < 41666UL ) //approx 2seconds
      {
        //update beat
        clock_time_uS = ( micros() - last_clock_uS ) / 48UL;
      } else {
        //first clock
        last_clock_uS = micros();
        sync_counter = 0;
        if ( vcob_note != 128 || vcoa_notes[0] != 128 || vcoa_notes[1] != 128 || vcoa_notes[1] != 128 )triggON();
      }
      break;



    case VCF_DC_AMOUNT_CC:   //filtre manuel
      if (flag_follow)
      {
        VCF_mixer.gain(0, float(( value - 64.0 ) / 64.0)); //-1.0 to 1.0
      } else {
        VCF_mixer.gain(0, float(value / 64.0)); // 0 to 2.0
      }

      break;

    case VCF_RESO_CC:
      VCF.resonance(float(value / 25.4)); // 0 to 5
      break;

    case VCF_ENV_AMOUNT_CC: //filtre adsr
      VCF_mixer.gain(1, float(value / 128.0));
      break;

    /** not in use */
    /*
      case VCF_HILOMID_HI_AMOUNT_CC:
      VCF_HILOMID_mixer.gain(2, float(value) / (128.0 ));
      break;
      // */

    case VCF_HILOMID_MID_AMOUNT_CC:
      VCF_HILOMID_mixer.gain(1, float(value) / (128.0 ));
      break;

    case VCF_HILOMID_LO_AMOUNT_CC:
      VCF_HILOMID_mixer.gain(0, float(value) / (128.0 ));
      break;

    case VCOA_VOLUME_CC:
      VCOs_mixer.gain(0, float(value / 64.0));
      VCOs_mixer.gain(1, float(value / 64.0));
      VCOs_mixer.gain(2, float(value / 64.0));
      break;

    case VCOB_VOLUME_CC:
      VCOs_mixer.gain(3, float(value / 64.0));
      break;

    case  MIDI_VOLUME_CC:
      VOL_dc_lvl.amplitude(float(value / 128.0));
      break;

    case VCOB_WAVEFORM_CC:
      VCOB.begin(WaveForm[value >> 4]);
      if (vcob_note != 128)
      {
        VCOB.frequency(midi2freq(vcob_note) * vcob_octave);
        VCOB.amplitude(0.25);
      } else {
        if (lowestMidiNote(vcoa_notes) != 128)
        {
          VCOB.frequency(midi2freq(lowestMidiNote(vcoa_notes)) * vcob_octave);
          VCOB.amplitude(0.25);
        }
      }
      break;

    case VCOA_WAVEFORM_CC:
      VCOA1.begin(WaveForm[value >> 4]);
      if (vcoa_notes[0] != 128)
      {
        VCOA1.frequency(midi2freq(vcoa_notes[0]));
        VCOA1.amplitude(0.25);
      } else {
        if ( lowestMidiNote(vcoa_notes) == 128 && vcob_note != 128 )
        {
          VCOA1.frequency(midi2freq(vcob_note));
          VCOA1.amplitude(0.25);
        }

      }
      //vcoa_notes[0] = 69;
      VCOA2.begin(WaveForm[value >> 4]);
      if (vcoa_notes[1] != 128)
      {
        VCOA2.frequency(midi2freq(vcoa_notes[1]));
        VCOA2.amplitude(0.25);
      }

      //vcoa_notes[1] = 69;
      VCOA3.begin(WaveForm[value >> 4]);
      if (vcoa_notes[2] != 128)
      {
        VCOA3.frequency(midi2freq(vcoa_notes[2]));
        VCOA3.amplitude(0.25);
      }

      //vcoa_notes[2] = 69;
      break;

    case VCF_LFO_AMOUNT_CC: //filtre LFO
      VCF_mixer.gain(2, float(value / 512.0));
      break;

    case VCF_LFO_FREQ_CC:
      VCF_lfo.frequency(float(value / 10.0)); //from 0 to 12.7Hz in 0.1Hz step
      break;

    case VCA_LFO_AMOUNT_CC:
      VCA_lfo.amplitude(float(value / 128.0));
      break;

    case VCA_LFO_FREQ_CC:
      VCA_lfo.frequency(float(value / 10.0)); //from 0 to 12.7Hz in 0.1Hz step
      break;

    case DELAY_DRY_LVL_CC: //dry/WET
      DELAY_mixer.gain(0, float((127.0 - value) / (128.0 * 2.0))); //
      //0 full wet
      //127 full dry
      DELAY_mixer.gain(1, float(value / (128.0 * 3.0))); //
      DELAY_mixer.gain(2, float(value / (128.0 * 6.0))); //
      DELAY_mixer.gain(3, float(value / (128.0 * 9.0))); //
      break;

    case DELAY_TIME_CC:
      DELAY.delay(2, float(value) * 12.0); //
      DELAY.delay(1, float(value) * 8.0); //
      DELAY.delay(0, float(value) * 4.0); //
      break;

    case VCOB_OCTAVE_UP_CC:
      if (value)
      {
        vcob_octave = 2.0;
      } else
      {
        vcob_octave = 1.0;
      }

      break;

    case VCF_LFO_AMOUNT_FLAG:
      if (value)
      {
        flag_vcf_lfo_amount = true;
      } else
      {
        flag_vcf_lfo_amount = false;
      }

      break;

    case VCF_LFO_FREQ_FLAG:
      if (value)
      {
        flag_vcf_lfo_freq = true;
      }
      else
      {
        flag_vcf_lfo_freq = false;
      }

      break;

    case VCA_LFO_AMOUNT_FLAG:
      if (value)
      {
        flag_vca_lfo_amount = true;
      } else
      {
        flag_vca_lfo_amount = false;
      }

      break;

    case VCA_LFO_FREQ_FLAG:
      if (value)
      {
        flag_vca_lfo_freq = true;
      }
      else
      {
        flag_vca_lfo_freq = false;
      }

      break;

    case DELAY_DRY_LVL_FLAG:
      if (value)
      {
        flag_delay_dry_lvl = true;
      }
      else
      {
        flag_delay_dry_lvl = false;
      }

      break;

    case DELAY_TIME_FLAG :
      if (value)
      {
        flag_delay_time = true;
      }
      else
      {
        flag_delay_time = false;
      }

      break;


    case VCOB_OCTAVE_DW_CC:
      if (value)
      {
        vcob_octave = 0.5;
      } else
      {
        vcob_octave = 1.0;
      }
      break;

    case  RETRIGG_CC:
      if (value)
      {
        flag_retrigg = true;
      } else {
        flag_retrigg = false;
      }
      break;

    case   HOLD_NOTE:
      if (value)
      {
        flag_hold = true;
      } else {
        flag_hold = false;
        handleNoteOff(0, vcoa_notes[0], 127);
        handleNoteOff(0, vcoa_notes[1], 127);
        handleNoteOff(0, vcoa_notes[2], 127);
        handleNoteOff(0, vcob_note, 127);
      }
      break;

    case  FOLLOW:
      if (value == 127)
      {
        flag_follow = true;
      } else {
        flag_follow = false;
        VCF.frequency(20.0);
      }
      break;



    //VCF adsr
    case VCF_ENV_ATTACK_TIME_CC:
      VCF_env.attack(value * 4);
      break;

    case VCF_ENV_DECAY_TIME_CC:
      VCF_env.decay(value * 4);
      break;

    case VCF_ENV_SUSTAIN_LVL_CC:
      VCF_env.sustain(float(value / 128.0));
      break;

    case VCF_ENV_RELEASE_TIME_CC:
      VCF_env.release(value * 8);
      break;


    //VCA adsr
    case VCA_ENV_ATTACK_TIME_CC:
      VCA_env.attack(value * 4);
      break;

    case VCA_ENV_DECAY_TIME_CC:
      VCA_env.decay(value * 4);
      break;

    case VCA_ENV_SUSTAIN_LVL_CC:
      VCA_env.sustain(float(value / 128.0));
      break;

    case VCA_ENV_RELEASE_TIME_CC:
      VCA_env.release(value * 8);
      break;

    case TAP_CC:
      handleControlChange( channel, CLOCK_IN_CC , value );
      tick_counter = 0;
      sync_counter = 0;
      break;


    //latch bank CC99
    case PRESET_BNK_2:
      if (value)
      {
        flagBank2 = true;
      } else
      {
        flagBank2 = false;
      }
      break;

    case VCF_LFO_WAVEFORM_CC:
      VCF_lfo.begin(WaveForm[value >> 4]);
      break;

    case VCA_LFO_WAVEFORM_CC:
      VCA_lfo.begin(WaveForm[value >> 4]);
      break;

    case  PRE_DELAY_REPEAT_CC:
      PRE_DELAY_mixer.gain(1, float(value / 127.0));//
      break;

    case  CLOCK_LENGHT_CC:
      clockOutLenght = max_tick * float(value / 127.0);
      break;

    case  CLOCK_DIVIDER_CC:
      max_tick = clockDividerArray[(value / 12)];
      break;


    case  CLOCK_ENABLE_CC:
      if (value)
      {
        flag_beatClock = true;
      }
      else
      {
        flag_beatClock = false;
      }
      break;


    default:
      // statements
      break;
  }

}

void handlePitchBend(byte channel, int bend)
{
  if (vcoa_notes[0] != 128)
  {
    VCOA1.frequency(midi2freqDetune( bend, vcoa_notes[0]));
  }
  if (vcoa_notes[1] != 128)
  {
    VCOA2.frequency(midi2freqDetune( bend, vcoa_notes[1]));
  }
  if (vcoa_notes[2] != 128)
  {
    VCOA3.frequency(midi2freqDetune( bend, vcoa_notes[2]));
  }
  if (vcob_note != 128)
  {
    VCOB.frequency(midi2freqDetune( bend, vcob_note));
  }
  return;

}

void handleSystemClock(void)
{
  return;
}

void handleSystemReset(void)
{
  triggOFF();
  handleNoteOff(0, vcoa_notes[0], 127);
  handleNoteOff(0, vcoa_notes[1], 127);
  handleNoteOff(0, vcoa_notes[2], 127);
  handleNoteOff(0, vcob_note, 127);
  /*
    vcoa_notes[0] = 128;
    vcoa_notes[1] = 128;
    vcoa_notes[2] = 128;
    vcob_note = 128;
    VCOA1.amplitude(0);
    VCOA2.amplitude(0);
    VCOA3.amplitude(0);
    VCOB.amplitude(0);
  */
}

void beatClock()
{
  unsigned long now_uS =  micros();

  if ( now_uS - last_Tick_uS >= clock_time_uS )
  {

    last_Tick_uS = now_uS;

    //  /
    tick_counter++;
    sync_counter++;

    // divided clock
    if ( tick_counter >= max_tick )
    {
      tick_counter = 0;
      if ( vcob_note != 128 || vcoa_notes[0] != 128 || vcoa_notes[1] != 128 || vcoa_notes[1] != 128 )triggON();
    }
    else if ( tick_counter >= clockOutLenght || tick_counter >= (max_tick - 1))
    {
      if ( vcob_note != 128 || vcoa_notes[0] != 128 || vcoa_notes[1] != 128 || vcoa_notes[1] != 128 )triggOFF();
    }

    //analog sync out
    if ( sync_counter >= 48 )
    {
      sync_counter = 0;
    }


  }

}

void setup() // */
{
  Entropy.Initialize();

  AudioMemory(550); //trying that on 3.6 (mostly needed for delay)

  VCOA1.begin(0, 220.0, 0);
  VCOA1.pulseWidth(28);
  // vcoa_notes[0] = 128;
  VCOA2.begin(0, 220.0, 0);
  VCOA2.pulseWidth(28);
  // vcoa_notes[1] = 128;
  VCOA3.begin(0, 220.0, 0);
  VCOA3.pulseWidth(28);
  // vcoa_notes[2] = 128;
  VCOB.begin(0, 440.0, 0);
  VCOB.pulseWidth(33);
  // vcob_note = 128;


  //init LFOs
  VCF_lfo.begin(0.33, 5.0, 0);
  VCA_lfo.begin(0.50, 5.0, 0);

  // init filter VCF
  VCF.octaveControl(7);
  VCF.frequency(20);

  // init VCF controls
  VCF_env_dc.amplitude(1.0);
  VCF_dc_lvl.amplitude(1.0);

  //VCOs_mixer.gain(3, 0.10);
  VCF_HILOMID_mixer.gain(2, 0.0);

  //init VCA controls
  VCA_dc_lvl.amplitude(1.0);

  // init filter ADSR
  VCF_env.hold(0);
  VCF_env.releaseNoteOn(0);

  // init VCA ADSR
  VCA_env.hold(0);
  VCA_env.releaseNoteOn(0);

  //init PRE_DELAY mixer
  PRE_DELAY_mixer.gain(0, 1);
  PRE_DELAY_mixer.gain(1, 0.80);
  PRE_DELAY_mixer.gain(2, 0);
  PRE_DELAY_mixer.gain(3, 0);

  //init PRE_DELAY_filter
  PRE_DELAY_filter.setHighShelf(0, 11000, 0, 1.0);

  //init output filter
  OUT_low_pass.setHighShelf(0, 11000, 0, 0.9);

  MIDI.setHandleNoteOn(handleNoteOn);  // Put only the name of the function
  // usbMIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);
  // usbMIDI.setHandleNoteOff(handleNoteOff);
  MIDI.setHandleControlChange(handleControlChange);
  // usbMIDI.setHandleControlChange(handleControlChange);
  MIDI.setHandlePitchBend(handlePitchBend);
  MIDI.setHandleClock(handleSystemClock);
  //usbMIDI.setHandleClock(handleSystemClock);
  MIDI.setHandleSystemReset(handleSystemReset);
  //usbMIDI.setHandleSystemReset(handleSystemReset);

  // Initiate MIDI communications, listen to all channels
  MIDI.begin(MIDI_CHANNEL_OMNI);

  vcoa_notes[0] = 128;
  VCOA1.amplitude(0);

  vcoa_notes[1] = 128;
  VCOA2.amplitude(0);

  vcoa_notes[2] = 128;
  VCOA3.amplitude(0);

  vcob_note = 128;
  VCOB.amplitude(0);

  triggOFF();

}

void loop()
{
  /* conflict with pith bend

    //add some "noise"
    if(vcoa_note[0] != 128)
    {
    VCOA1.frequency(midi2freq( vcoa_note[0]));
    }
    if(vcoa_note[1] != 128)
    {
    VCOA2.frequency(midi2freq( vcoa_note[1]));
    }
    if(vcoa_note[2] != 128)
    {
    VCOA3.frequency(midi2freq( vcoa_note[2]));
    }
    if(vcob_note != 128)
    {
    VCOB.frequency(midi2freqDetune( vcob_note ));
    }
  */
  if (flag_beatClock)
  {
    beatClock();
  }


  MIDI.read();
  //usbMIDI.read();
}


//eof

