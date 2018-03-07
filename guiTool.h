/*
// GUItool: begin automatically generated code
AudioSynthWaveformDc     VCF_env_dc;            //xy=66.00000381469727,595.3203163146973
AudioEffectEnvelope      VCF_env;      //xy=207.31330490112305,595.3207120895386
AudioSynthWaveform       VCF_lfo;      //xy=208.90052795410156,631.1227788925171
AudioSynthWaveform       VCOA1;      //xy=212.46528244018555,383.3541784286499
AudioSynthWaveform       VCOA3;      //xy=212.23379516601562,460.25849437713623
AudioSynthWaveform       VCOB;      //xy=212.2337875366211,499.14740562438965
AudioSynthWaveform       VCOA2;      //xy=213.34489610460068,421.3696034749349
AudioSynthWaveformDc     VCF_dc_lvl;            //xy=213.34490203857422,561.0116119384766
AudioMixer4              VCF_mixer;         //xy=378.9481964111328,580.1387577056885
AudioMixer4              VCOs_mixer;         //xy=385.56713104248047,439.14738845825195
AudioSynthWaveformDc     VCA_env_dc;            //xy=434.42444610595703,694.4561729431152
AudioFilterStateVariable VCF;        //xy=553.3449478149414,445.3202095031738
AudioSynthWaveform       VCA_lfo;      //xy=573.3449783325195,730.0116786956787
AudioSynthWaveformDc     VCA_dc_lvl;            //xy=576.678229437934,660.0115712483724
AudioEffectEnvelope      VCA_env;      //xy=580.0116500854492,694.4562692642212
AudioMixer4              VCF_HILOMID_mixer;         //xy=721.1227149963379,451.9869270324707
AudioMixer4              VCA_mixer;         //xy=743.503719329834,690.4877548217773
AudioEffectMultiply      VCA;      //xy=895.5671806335449,458.90044021606445
AudioEffectDelay         DELAY;         //xy=937.7089385986328,628.6613006591797
AudioMixer4              DELAY_mixer;         //xy=1107.081771850586,588.8518142700195
AudioOutputAnalogStereo  AUDIO_out;          //xy=1107.9220962524414,673.7433595657349
AudioConnection          patchCord1(VCF_env_dc, VCF_env);
AudioConnection          patchCord2(VCF_env, 0, VCF_mixer, 1);
AudioConnection          patchCord3(VCF_lfo, 0, VCF_mixer, 2);
AudioConnection          patchCord4(VCOA1, 0, VCOs_mixer, 0);
AudioConnection          patchCord5(VCOA3, 0, VCOs_mixer, 2);
AudioConnection          patchCord6(VCOB, 0, VCOs_mixer, 3);
AudioConnection          patchCord7(VCOA2, 0, VCOs_mixer, 1);
AudioConnection          patchCord8(VCF_dc_lvl, 0, VCF_mixer, 0);
AudioConnection          patchCord9(VCF_mixer, 0, VCF, 1);
AudioConnection          patchCord10(VCOs_mixer, 0, VCF, 0);
AudioConnection          patchCord11(VCA_env_dc, VCA_env);
AudioConnection          patchCord12(VCF, 0, VCF_HILOMID_mixer, 0);
AudioConnection          patchCord13(VCF, 1, VCF_HILOMID_mixer, 1);
AudioConnection          patchCord14(VCF, 2, VCF_HILOMID_mixer, 2);
AudioConnection          patchCord15(VCA_lfo, 0, VCA_mixer, 2);
AudioConnection          patchCord16(VCA_dc_lvl, 0, VCA_mixer, 0);
AudioConnection          patchCord17(VCA_env, 0, VCA_mixer, 1);
AudioConnection          patchCord18(VCF_HILOMID_mixer, 0, VCA, 0);
AudioConnection          patchCord19(VCA_mixer, 0, VCA, 1);
AudioConnection          patchCord20(VCA, DELAY);
AudioConnection          patchCord21(VCA, 0, DELAY_mixer, 0);
AudioConnection          patchCord22(DELAY, 0, DELAY_mixer, 1);
AudioConnection          patchCord23(DELAY, 1, DELAY_mixer, 2);
AudioConnection          patchCord24(DELAY, 2, DELAY_mixer, 3);
AudioConnection          patchCord25(DELAY_mixer, 0, AUDIO_out, 0);
AudioConnection          patchCord26(DELAY_mixer, 0, AUDIO_out, 1);
// GUItool: end automatically generated code
*/
/*
// GUItool: begin automatically generated code
AudioSynthWaveformDc     VCF_env_dc;            //xy=66.00000381469727,595.3203163146973
AudioEffectEnvelope      VCF_env;      //xy=207.31330490112305,595.3207120895386
AudioSynthWaveform       VCF_lfo;      //xy=208.90052795410156,631.1227788925171
AudioSynthWaveform       VCOA1;      //xy=212.46528244018555,383.3541784286499
AudioSynthWaveform       VCOA3;      //xy=212.23379516601562,460.25849437713623
AudioSynthWaveform       VCOB;      //xy=212.2337875366211,499.14740562438965
AudioSynthWaveform       VCOA2;      //xy=213.34489610460068,421.3696034749349
AudioSynthWaveformDc     VCF_dc_lvl;            //xy=213.34490203857422,561.0116119384766
AudioMixer4              VCF_mixer;         //xy=378.9481964111328,580.1387577056885
AudioSynthWaveformDc     VCA_dc_lvl;            //xy=382.85714285714283,685.7142857142857
AudioMixer4              VCOs_mixer;         //xy=385.56713104248047,439.14738845825195
AudioSynthWaveform       VCA_lfo;      //xy=386.2021064758301,741.4402513504028
AudioMixer4              VCA_mixer;         //xy=531.4285888671875,712.857120513916
AudioFilterStateVariable VCF;        //xy=553.3449478149414,445.3202095031738
AudioEffectMultiply      VCA;      //xy=624.1385841369629,541.7575588226318
AudioMixer4              VCF_HILOMID_mixer;         //xy=721.1227149963379,451.9869270324707
AudioEffectEnvelope      VCA_env;      //xy=747.1545677185059,543.027702331543
AudioEffectDelay         DELAY;         //xy=937.7089385986328,628.6613006591797
AudioMixer4              DELAY_mixer;         //xy=1107.081771850586,588.8518142700195
AudioOutputAnalogStereo  AUDIO_out;          //xy=1107.9220962524414,673.7433595657349
AudioConnection          patchCord1(VCF_env_dc, VCF_env);
AudioConnection          patchCord2(VCF_env, 0, VCF_mixer, 1);
AudioConnection          patchCord3(VCF_lfo, 0, VCF_mixer, 2);
AudioConnection          patchCord4(VCOA1, 0, VCOs_mixer, 0);
AudioConnection          patchCord5(VCOA3, 0, VCOs_mixer, 2);
AudioConnection          patchCord6(VCOB, 0, VCOs_mixer, 3);
AudioConnection          patchCord7(VCOA2, 0, VCOs_mixer, 1);
AudioConnection          patchCord8(VCF_dc_lvl, 0, VCF_mixer, 0);
AudioConnection          patchCord9(VCF_mixer, 0, VCF, 1);
AudioConnection          patchCord10(VCA_dc_lvl, 0, VCA_mixer, 0);
AudioConnection          patchCord11(VCOs_mixer, 0, VCF, 0);
AudioConnection          patchCord12(VCA_lfo, 0, VCA_mixer, 1);
AudioConnection          patchCord13(VCA_mixer, 0, VCA, 1);
AudioConnection          patchCord14(VCF, 0, VCF_HILOMID_mixer, 0);
AudioConnection          patchCord15(VCF, 1, VCF_HILOMID_mixer, 1);
AudioConnection          patchCord16(VCF, 2, VCF_HILOMID_mixer, 2);
AudioConnection          patchCord17(VCA, VCA_env);
AudioConnection          patchCord18(VCF_HILOMID_mixer, 0, VCA, 0);
AudioConnection          patchCord19(VCA_env, DELAY);
AudioConnection          patchCord20(VCA_env, 0, DELAY_mixer, 0);
AudioConnection          patchCord21(DELAY, 0, DELAY_mixer, 1);
AudioConnection          patchCord22(DELAY, 1, DELAY_mixer, 2);
AudioConnection          patchCord23(DELAY, 2, DELAY_mixer, 3);
AudioConnection          patchCord24(DELAY_mixer, 0, AUDIO_out, 0);
AudioConnection          patchCord25(DELAY_mixer, 0, AUDIO_out, 1);
// GUItool: end automatically generated code

*/

/*
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformDc     VCF_env_dc;     //xy=86,2615
AudioEffectEnvelope      VCF_env;        //xy=227,2615
AudioSynthWaveform       VCF_lfo;        //xy=228,2651
AudioSynthWaveform       VCOA1;          //xy=232,2403
AudioSynthWaveform       VCOA3;          //xy=232,2480
AudioSynthWaveform       VCOB;           //xy=232,2519
AudioSynthWaveform       VCOA2;          //xy=233,2441
AudioSynthWaveformDc     VCF_dc_lvl;     //xy=233,2581
AudioSynthWaveformDc     VCA_dc_lvl;     //xy=249.50000762939453,2717.5000400543213
AudioSynthWaveform       VCA_lfo;        //xy=253.50000762939453,2773.5000400543213
AudioMixer4              VCF_mixer;      //xy=398,2600
AudioMixer4              VCA_mixer;      //xy=398.50000762939453,2744.5000400543213
AudioMixer4              VCOs_mixer;     //xy=405,2459
AudioFilterStateVariable VCF;            //xy=573,2465
AudioEffectMultiply      VCA;            //xy=644,2561
AudioMixer4              VCF_HILOMID_mixer; //xy=741,2471
AudioMixer4              PRE_DELAY_mixer;         //xy=754,2683
AudioEffectEnvelope      VCA_env;        //xy=767,2563
AudioEffectDelay         DELAY;          //xy=945.7500133514404,2684.2500381469727
AudioOutputAnalogStereo  AUDIO_out;      //xy=1127,2693
AudioMixer4              DELAY_mixer;    //xy=1133.250015258789,2581.7500381469727
AudioConnection          patchCord1(VCF_env_dc, VCF_env);
AudioConnection          patchCord2(VCF_env, 0, VCF_mixer, 1);
AudioConnection          patchCord3(VCF_lfo, 0, VCF_mixer, 2);
AudioConnection          patchCord4(VCOA1, 0, VCOs_mixer, 0);
AudioConnection          patchCord5(VCOA3, 0, VCOs_mixer, 2);
AudioConnection          patchCord6(VCOB, 0, VCOs_mixer, 3);
AudioConnection          patchCord7(VCOA2, 0, VCOs_mixer, 1);
AudioConnection          patchCord8(VCF_dc_lvl, 0, VCF_mixer, 0);
AudioConnection          patchCord9(VCA_dc_lvl, 0, VCA_mixer, 0);
AudioConnection          patchCord10(VCA_lfo, 0, VCA_mixer, 1);
AudioConnection          patchCord11(VCF_mixer, 0, VCF, 1);
AudioConnection          patchCord12(VCA_mixer, 0, VCA, 1);
AudioConnection          patchCord13(VCOs_mixer, 0, VCF, 0);
AudioConnection          patchCord14(VCF, 0, VCF_HILOMID_mixer, 0);
AudioConnection          patchCord15(VCF, 1, VCF_HILOMID_mixer, 1);
AudioConnection          patchCord16(VCF, 2, VCF_HILOMID_mixer, 2);
AudioConnection          patchCord17(VCA, VCA_env);
AudioConnection          patchCord18(VCF_HILOMID_mixer, 0, VCA, 0);
AudioConnection          patchCord19(PRE_DELAY_mixer, DELAY);
AudioConnection          patchCord20(VCA_env, 0, DELAY_mixer, 0);
AudioConnection          patchCord21(VCA_env, 0, PRE_DELAY_mixer, 0);
AudioConnection          patchCord22(DELAY, 0, DELAY_mixer, 1);
AudioConnection          patchCord23(DELAY, 0, PRE_DELAY_mixer, 1);
AudioConnection          patchCord24(DELAY, 1, DELAY_mixer, 2);
AudioConnection          patchCord25(DELAY, 2, DELAY_mixer, 3);
AudioConnection          patchCord26(DELAY_mixer, 0, AUDIO_out, 0);
AudioConnection          patchCord27(DELAY_mixer, 0, AUDIO_out, 1);
// GUItool: end automatically generated code
*/

/*
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformDc     VCF_env_dc;     //xy=88.8571548461914,305.5714235305786
AudioSynthWaveform       VCF_lfo;        //xy=225.1428565979004,340.1428470611572
AudioEffectEnvelope      VCF_env;        //xy=229.8571548461914,305.5714235305786
AudioSynthWaveform       VCOA1;          //xy=234.8571548461914,93.57142353057861
AudioSynthWaveform       VCOA3;          //xy=234.8571548461914,170.5714235305786
AudioSynthWaveform       VCOB;           //xy=234.8571548461914,209.5714235305786
AudioSynthWaveform       VCOA2;          //xy=235.8571548461914,131.5714235305786
AudioSynthWaveformDc     VCF_dc_lvl;     //xy=235.8571548461914,271.5714235305786
AudioSynthWaveform       VCA_lfo;        //xy=241.57143020629883,443.57142543792725
AudioSynthWaveformDc     VCA_dc_lvl;     //xy=251.8571548461914,407.5714235305786
AudioMixer4              VCF_mixer;      //xy=400.8571548461914,290.5714235305786
AudioMixer4              VCA_mixer;      //xy=400.8571548461914,434.5714235305786
AudioMixer4              VCOs_mixer;     //xy=407.8571548461914,149.5714235305786
AudioFilterStateVariable VCF;            //xy=575.8571548461914,155.5714235305786
AudioEffectMultiply      VCA;            //xy=646.8571548461914,251.5714235305786
AudioEffectDelay         DELAY;          //xy=700.3571929931641,360.82141876220703
AudioMixer4              VCF_HILOMID_mixer; //xy=743.8571548461914,161.5714235305786
AudioEffectEnvelope      VCA_env;        //xy=785.571460723877,252.14284896850586
AudioMixer4              PRE_DELAY_mixer; //xy=1101.857192993164,418.57141876220703
AudioMixer4              DELAY_mixer;    //xy=1135.8571548461914,271.5714235305786
AudioOutputAnalogStereo  AUDIO_out;      //xy=1141.1071968078613,342.32141494750977
AudioConnection          patchCord1(VCF_env_dc, VCF_env);
AudioConnection          patchCord2(VCF_lfo, 0, VCF_mixer, 2);
AudioConnection          patchCord3(VCF_env, 0, VCF_mixer, 1);
AudioConnection          patchCord4(VCOA1, 0, VCOs_mixer, 0);
AudioConnection          patchCord5(VCOA3, 0, VCOs_mixer, 2);
AudioConnection          patchCord6(VCOB, 0, VCOs_mixer, 3);
AudioConnection          patchCord7(VCOA2, 0, VCOs_mixer, 1);
AudioConnection          patchCord8(VCF_dc_lvl, 0, VCF_mixer, 0);
AudioConnection          patchCord9(VCA_lfo, 0, VCA_mixer, 1);
AudioConnection          patchCord10(VCA_dc_lvl, 0, VCA_mixer, 0);
AudioConnection          patchCord11(VCF_mixer, 0, VCF, 1);
AudioConnection          patchCord12(VCA_mixer, 0, VCA, 1);
AudioConnection          patchCord13(VCOs_mixer, 0, VCF, 0);
AudioConnection          patchCord14(VCF, 0, VCF_HILOMID_mixer, 0);
AudioConnection          patchCord15(VCF, 1, VCF_HILOMID_mixer, 1);
AudioConnection          patchCord16(VCF, 2, VCF_HILOMID_mixer, 2);
AudioConnection          patchCord17(VCA, VCA_env);
AudioConnection          patchCord18(DELAY, 0, DELAY_mixer, 1);
AudioConnection          patchCord19(DELAY, 0, PRE_DELAY_mixer, 1);
AudioConnection          patchCord20(DELAY, 1, DELAY_mixer, 2);
AudioConnection          patchCord21(DELAY, 1, PRE_DELAY_mixer, 2);
AudioConnection          patchCord22(DELAY, 2, DELAY_mixer, 3);
AudioConnection          patchCord23(DELAY, 2, PRE_DELAY_mixer, 3);
AudioConnection          patchCord24(VCF_HILOMID_mixer, 0, VCA, 0);
AudioConnection          patchCord25(VCA_env, 0, DELAY_mixer, 0);
AudioConnection          patchCord26(VCA_env, 0, PRE_DELAY_mixer, 0);
AudioConnection          patchCord27(PRE_DELAY_mixer, DELAY);
AudioConnection          patchCord28(DELAY_mixer, 0, AUDIO_out, 0);
AudioConnection          patchCord29(DELAY_mixer, 0, AUDIO_out, 1);
// GUItool: end automatically generated code
*/

/*
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformDc     VCF_env_dc;     //xy=88.8571548461914,305.5714235305786
AudioSynthWaveform       VCF_lfo;        //xy=225.1428565979004,340.1428470611572
AudioEffectEnvelope      VCF_env;        //xy=229.8571548461914,305.5714235305786
AudioSynthWaveform       VCOA1;          //xy=234.8571548461914,93.57142353057861
AudioSynthWaveform       VCOA3;          //xy=234.8571548461914,170.5714235305786
AudioSynthWaveform       VCOB;           //xy=234.8571548461914,209.5714235305786
AudioSynthWaveform       VCOA2;          //xy=235.8571548461914,131.5714235305786
AudioSynthWaveformDc     VCF_dc_lvl;     //xy=235.8571548461914,271.5714235305786
AudioSynthWaveform       VCA_lfo;        //xy=241.57143020629883,443.57142543792725
AudioSynthWaveformDc     VCA_dc_lvl;     //xy=251.8571548461914,407.5714235305786
AudioMixer4              VCF_mixer;      //xy=400.8571548461914,290.5714235305786
AudioMixer4              VCA_mixer;      //xy=400.8571548461914,434.5714235305786
AudioMixer4              VCOs_mixer;     //xy=407.8571548461914,149.5714235305786
AudioFilterStateVariable VCF;            //xy=575.8571548461914,155.5714235305786
AudioEffectMultiply      VCA;            //xy=646.8571548461914,251.5714235305786
AudioMixer4              PRE_DELAY_mixer; //xy=674.3571853637695,447.32141876220703
AudioMixer4              VCF_HILOMID_mixer; //xy=743.8571548461914,161.5714235305786
AudioEffectEnvelope      VCA_env;        //xy=785.571460723877,252.14284896850586
AudioEffectDelay         DELAY;          //xy=894.1071891784668,338.32141876220703
AudioSynthWaveformDc     VOL_dc_lvl;            //xy=1031.4285697937012,377.6190538406372
AudioMixer4              DELAY_mixer;    //xy=1135.8571548461914,271.5714235305786
AudioOutputAnalogStereo  AUDIO_out;      //xy=1154.8571586608887,536.9642534255981
AudioEffectMultiply      VOL;      //xy=1167.1428718566895,368.57143783569336
AudioConnection          patchCord1(VCF_env_dc, VCF_env);
AudioConnection          patchCord2(VCF_lfo, 0, VCF_mixer, 2);
AudioConnection          patchCord3(VCF_env, 0, VCF_mixer, 1);
AudioConnection          patchCord4(VCOA1, 0, VCOs_mixer, 0);
AudioConnection          patchCord5(VCOA3, 0, VCOs_mixer, 2);
AudioConnection          patchCord6(VCOB, 0, VCOs_mixer, 3);
AudioConnection          patchCord7(VCOA2, 0, VCOs_mixer, 1);
AudioConnection          patchCord8(VCF_dc_lvl, 0, VCF_mixer, 0);
AudioConnection          patchCord9(VCA_lfo, 0, VCA_mixer, 1);
AudioConnection          patchCord10(VCA_dc_lvl, 0, VCA_mixer, 0);
AudioConnection          patchCord11(VCF_mixer, 0, VCF, 1);
AudioConnection          patchCord12(VCA_mixer, 0, VCA, 1);
AudioConnection          patchCord13(VCOs_mixer, 0, VCF, 0);
AudioConnection          patchCord14(VCF, 0, VCF_HILOMID_mixer, 0);
AudioConnection          patchCord15(VCF, 1, VCF_HILOMID_mixer, 1);
AudioConnection          patchCord16(VCF, 2, VCF_HILOMID_mixer, 2);
AudioConnection          patchCord17(VCA, VCA_env);
AudioConnection          patchCord18(PRE_DELAY_mixer, DELAY);
AudioConnection          patchCord19(VCF_HILOMID_mixer, 0, VCA, 0);
AudioConnection          patchCord20(VCA_env, 0, DELAY_mixer, 0);
AudioConnection          patchCord21(VCA_env, 0, PRE_DELAY_mixer, 0);
AudioConnection          patchCord22(DELAY, 0, DELAY_mixer, 1);
AudioConnection          patchCord23(DELAY, 0, PRE_DELAY_mixer, 1);
AudioConnection          patchCord24(DELAY, 1, DELAY_mixer, 2);
AudioConnection          patchCord25(DELAY, 1, PRE_DELAY_mixer, 2);
AudioConnection          patchCord26(DELAY, 2, DELAY_mixer, 3);
AudioConnection          patchCord27(DELAY, 2, PRE_DELAY_mixer, 3);
AudioConnection          patchCord28(VOL_dc_lvl, 0, VOL, 1);
AudioConnection          patchCord29(DELAY_mixer, 0, VOL, 0);
AudioConnection          patchCord30(VOL, 0, AUDIO_out, 0);
AudioConnection          patchCord31(VOL, 0, AUDIO_out, 1);
// GUItool: end automatically generated code
*/
/*
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveform       VCOB;           //xy=71.52383041381836,211.23808670043945
AudioSynthWaveform       VCO_ring;      //xy=75.00003433227539,251.66666507720947
AudioSynthWaveform       VCOA1;          //xy=76.52383422851562,93.57142639160156
AudioSynthWaveform       VCOA3;          //xy=76.52383422851562,170.57142639160156
AudioSynthWaveform       VCOA2;          //xy=77.52383422851562,131.57142639160156
AudioSynthWaveformDc     VCF_env_dc;     //xy=88.8571548461914,305.5714235305786
AudioSynthWaveform       VCF_lfo;        //xy=225.1428565979004,340.1428470611572
AudioEffectEnvelope      VCF_env;        //xy=229.8571548461914,305.5714235305786
AudioSynthWaveformDc     VCF_dc_lvl;     //xy=235.8571548461914,271.5714235305786
AudioSynthWaveform       VCA_lfo;        //xy=241.57143020629883,443.57142543792725
AudioMixer4              VCOs_mixer;     //xy=249.52383422851562,149.57142639160156
AudioSynthWaveformDc     VCA_dc_lvl;     //xy=251.8571548461914,407.5714235305786
AudioEffectMultiply      RING;      //xy=394.9999351501465,215.0000123977661
AudioMixer4              VCF_mixer;      //xy=400.8571548461914,290.5714235305786
AudioMixer4              VCA_mixer;      //xy=400.8571548461914,434.5714235305786
AudioFilterStateVariable VCF;            //xy=575.8571548461914,155.5714235305786
AudioEffectMultiply      VCA;            //xy=646.8571548461914,251.5714235305786
AudioMixer4              PRE_DELAY_mixer; //xy=674.3571853637695,447.32141876220703
AudioMixer4              VCF_HILOMID_mixer; //xy=743.8571548461914,161.5714235305786
AudioEffectEnvelope      VCA_env;        //xy=785.571460723877,252.14284896850586
AudioEffectDelay         DELAY;          //xy=894.1071891784668,338.32141876220703
AudioSynthWaveformDc     VOL_dc_lvl;            //xy=1031.4285697937012,377.6190538406372
AudioMixer4              DELAY_mixer;    //xy=1135.8571548461914,271.5714235305786
AudioOutputAnalogStereo  AUDIO_out;      //xy=1154.8571586608887,536.9642534255981
AudioEffectMultiply      VOL;      //xy=1167.1428718566895,368.57143783569336
AudioConnection          patchCord1(VCOB, 0, RING, 0);
AudioConnection          patchCord2(VCOB, 0, VCOs_mixer, 3);
AudioConnection          patchCord3(VCO_ring, 0, RING, 1);
AudioConnection          patchCord4(VCOA1, 0, VCOs_mixer, 0);
AudioConnection          patchCord5(VCOA3, 0, VCOs_mixer, 2);
AudioConnection          patchCord6(VCOA2, 0, VCOs_mixer, 1);
AudioConnection          patchCord7(VCF_env_dc, VCF_env);
AudioConnection          patchCord8(VCF_lfo, 0, VCF_mixer, 2);
AudioConnection          patchCord9(VCF_env, 0, VCF_mixer, 1);
AudioConnection          patchCord10(VCF_dc_lvl, 0, VCF_mixer, 0);
AudioConnection          patchCord11(VCA_lfo, 0, VCA_mixer, 1);
AudioConnection          patchCord12(VCOs_mixer, 0, VCF, 0);
AudioConnection          patchCord13(VCA_dc_lvl, 0, VCA_mixer, 0);
AudioConnection          patchCord14(RING, 0, VCF_HILOMID_mixer, 3);
AudioConnection          patchCord15(VCF_mixer, 0, VCF, 1);
AudioConnection          patchCord16(VCA_mixer, 0, VCA, 1);
AudioConnection          patchCord17(VCF, 0, VCF_HILOMID_mixer, 0);
AudioConnection          patchCord18(VCF, 1, VCF_HILOMID_mixer, 1);
AudioConnection          patchCord19(VCF, 2, VCF_HILOMID_mixer, 2);
AudioConnection          patchCord20(VCA, VCA_env);
AudioConnection          patchCord21(PRE_DELAY_mixer, DELAY);
AudioConnection          patchCord22(VCF_HILOMID_mixer, 0, VCA, 0);
AudioConnection          patchCord23(VCA_env, 0, DELAY_mixer, 0);
AudioConnection          patchCord24(VCA_env, 0, PRE_DELAY_mixer, 0);
AudioConnection          patchCord25(DELAY, 0, DELAY_mixer, 1);
AudioConnection          patchCord26(DELAY, 0, PRE_DELAY_mixer, 1);
AudioConnection          patchCord27(DELAY, 1, DELAY_mixer, 2);
AudioConnection          patchCord28(DELAY, 1, PRE_DELAY_mixer, 2);
AudioConnection          patchCord29(DELAY, 2, DELAY_mixer, 3);
AudioConnection          patchCord30(DELAY, 2, PRE_DELAY_mixer, 3);
AudioConnection          patchCord31(VOL_dc_lvl, 0, VOL, 1);
AudioConnection          patchCord32(DELAY_mixer, 0, VOL, 0);
AudioConnection          patchCord33(VOL, 0, AUDIO_out, 0);
AudioConnection          patchCord34(VOL, 0, AUDIO_out, 1);
// GUItool: end automatically generated code
*/

/*
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveform       VCO_ring;       //xy=98.50000762939453,2720.000410079956
AudioSynthWaveform       VCOB;           //xy=102,2680
AudioSynthWaveform       VCOA1;          //xy=107,2562
AudioSynthWaveform       VCOA3;          //xy=107,2639
AudioSynthWaveform       VCOA2;          //xy=108,2600
AudioSynthWaveformDc     VCF_env_dc;     //xy=119,2774
AudioSynthWaveform       VCF_lfo;        //xy=256,2809
AudioEffectEnvelope      VCF_env;        //xy=260,2774
AudioSynthWaveformDc     VCA_dc_lvl;     //xy=264.5,2872.249991416931
AudioSynthWaveformDc     VCF_dc_lvl;     //xy=266,2740
AudioSynthWaveform       VCA_lfo;        //xy=275.74999618530273,2907.000157356262
AudioMixer4              VCOs_mixer;     //xy=318.74999237060547,2618.0000228881836
AudioEffectMultiply      RING;           //xy=425,2684
AudioMixer4              VCF_mixer;      //xy=431,2759
AudioMixer4              VCA_mixer;      //xy=431,2903
AudioFilterStateVariable VCF;            //xy=606,2624
AudioMixer4              PRE_DELAY_mixer; //xy=630.0000381469727,2974.888967514038
AudioEffectMultiply      VCA;            //xy=677,2720
AudioEffectEnvelope      VCA_env;        //xy=816,2721
AudioMixer4              VCF_HILOMID_mixer; //xy=829.0000457763672,2630.000078201294
AudioFilterBiquad        PRE_DELAY_filter;        //xy=835.8464050292969,2974.179874420166
AudioEffectDelay         DELAY;          //xy=925,2807
AudioSynthWaveformDc     VOL_dc_lvl;     //xy=1055.7500648498535,2946.000075340271
AudioFilterBiquad        OUT_low_pass;        //xy=1140.0131759643555,2841.8191862106323
AudioOutputAnalogStereo  AUDIO_out;      //xy=1155.0000343322754,3105.0000019073486
AudioMixer4              DELAY_mixer;    //xy=1166,2740
AudioEffectMultiply      VOL;            //xy=1198.0000038146973,2939.5001220703125
AudioConnection          patchCord1(VCO_ring, 0, RING, 1);
AudioConnection          patchCord2(VCOB, 0, RING, 0);
AudioConnection          patchCord3(VCOB, 0, VCOs_mixer, 3);
AudioConnection          patchCord4(VCOA1, 0, VCOs_mixer, 0);
AudioConnection          patchCord5(VCOA3, 0, VCOs_mixer, 2);
AudioConnection          patchCord6(VCOA2, 0, VCOs_mixer, 1);
AudioConnection          patchCord7(VCF_env_dc, VCF_env);
AudioConnection          patchCord8(VCF_lfo, 0, VCF_mixer, 2);
AudioConnection          patchCord9(VCF_env, 0, VCF_mixer, 1);
AudioConnection          patchCord10(VCA_dc_lvl, 0, VCA_mixer, 0);
AudioConnection          patchCord11(VCF_dc_lvl, 0, VCF_mixer, 0);
AudioConnection          patchCord12(VCA_lfo, 0, VCA_mixer, 1);
AudioConnection          patchCord13(VCOs_mixer, 0, VCF, 0);
AudioConnection          patchCord14(RING, 0, VCF_HILOMID_mixer, 3);
AudioConnection          patchCord15(VCF_mixer, 0, VCF, 1);
AudioConnection          patchCord16(VCA_mixer, 0, VCA, 1);
AudioConnection          patchCord17(VCF, 0, VCF_HILOMID_mixer, 0);
AudioConnection          patchCord18(VCF, 1, VCF_HILOMID_mixer, 1);
AudioConnection          patchCord19(VCF, 2, VCF_HILOMID_mixer, 2);
AudioConnection          patchCord20(PRE_DELAY_mixer, PRE_DELAY_filter);
AudioConnection          patchCord21(VCA, VCA_env);
AudioConnection          patchCord22(VCA_env, 0, PRE_DELAY_mixer, 0);
AudioConnection          patchCord23(VCA_env, 0, DELAY_mixer, 0);
AudioConnection          patchCord24(VCF_HILOMID_mixer, 0, VCA, 0);
AudioConnection          patchCord25(PRE_DELAY_filter, DELAY);
AudioConnection          patchCord26(DELAY, 0, DELAY_mixer, 1);
AudioConnection          patchCord27(DELAY, 0, PRE_DELAY_mixer, 1);
AudioConnection          patchCord28(DELAY, 1, DELAY_mixer, 2);
AudioConnection          patchCord29(DELAY, 1, PRE_DELAY_mixer, 2);
AudioConnection          patchCord30(DELAY, 2, DELAY_mixer, 3);
AudioConnection          patchCord31(DELAY, 2, PRE_DELAY_mixer, 3);
AudioConnection          patchCord32(VOL_dc_lvl, 0, VOL, 1);
AudioConnection          patchCord33(OUT_low_pass, 0, VOL, 0);
AudioConnection          patchCord34(DELAY_mixer, OUT_low_pass);
AudioConnection          patchCord35(VOL, 0, AUDIO_out, 0);
AudioConnection          patchCord36(VOL, 0, AUDIO_out, 1);
// GUItool: end automatically generated code
*/

// GUItool: begin automatically generated code
AudioSynthWaveform       VCOB;           //xy=114.33333587646484,256.3333282470703
AudioSynthWaveform       VCOA1;          //xy=116,140
AudioSynthWaveform       VCOA3;          //xy=116,217
AudioSynthWaveform       VCOA2;          //xy=117,178
AudioSynthWaveformDc     VCF_env_dc;     //xy=128,352
AudioSynthWaveformDc     VCF_dc_lvl;     //xy=266.6666793823242,317.99999237060547
AudioEffectEnvelope      VCF_env;        //xy=269,352
AudioSynthWaveformDc     VCA_dc_lvl;     //xy=273,450
AudioSynthWaveform       VCF_lfo;        //xy=273.33333587646484,386.9999942779541
AudioSynthWaveform       VCA_lfo;        //xy=284,485
AudioMixer4              VCOs_mixer;     //xy=327,196
AudioMixer4              VCF_mixer;      //xy=440,337
AudioMixer4              VCA_mixer;      //xy=440,481
AudioFilterStateVariable VCF;            //xy=615,202
AudioEffectMultiply      VCA;            //xy=686,298
AudioMixer4              PRE_DELAY_mixer; //xy=725.1667633056641,569.5000686645508
AudioFilterBiquad        PRE_DELAY_filter; //xy=731.5001220703125,431.1666889190674
AudioEffectEnvelope      VCA_env;        //xy=815.6666374206543,298.00000190734863
AudioMixer4              VCF_HILOMID_mixer; //xy=838,208
AudioEffectDelay         DELAY;          //xy=904.0000762939453,537.5000076293945
AudioSynthWaveformDc     VOL_dc_lvl;     //xy=1029.833351135254,685.6667137145996
AudioFilterBiquad        OUT_low_pass;   //xy=1158.1667518615723,554.0000419616699
AudioMixer4              DELAY_mixer;    //xy=1180.8335189819336,444.6666622161865
AudioEffectMultiply      VOL;            //xy=1181.1667938232422,678.6666793823242
AudioOutputAnalogStereo  AUDIO_out;      //xy=1354.833381652832,679.6667003631592
AudioConnection          patchCord1(VCOB, 0, VCOs_mixer, 3);
AudioConnection          patchCord2(VCOA1, 0, VCOs_mixer, 0);
AudioConnection          patchCord3(VCOA3, 0, VCOs_mixer, 2);
AudioConnection          patchCord4(VCOA2, 0, VCOs_mixer, 1);
AudioConnection          patchCord5(VCF_env_dc, VCF_env);
AudioConnection          patchCord6(VCF_dc_lvl, 0, VCF_mixer, 0);
AudioConnection          patchCord7(VCF_env, 0, VCF_mixer, 1);
AudioConnection          patchCord8(VCA_dc_lvl, 0, VCA_mixer, 0);
AudioConnection          patchCord9(VCF_lfo, 0, VCF_mixer, 2);
AudioConnection          patchCord10(VCA_lfo, 0, VCA_mixer, 1);
AudioConnection          patchCord11(VCOs_mixer, 0, VCF, 0);
AudioConnection          patchCord12(VCF_mixer, 0, VCF, 1);
AudioConnection          patchCord13(VCA_mixer, 0, VCA, 1);
AudioConnection          patchCord14(VCF, 0, VCF_HILOMID_mixer, 0);
AudioConnection          patchCord15(VCF, 1, VCF_HILOMID_mixer, 1);
AudioConnection          patchCord16(VCF, 2, VCF_HILOMID_mixer, 2);
AudioConnection          patchCord17(VCA, VCA_env);
AudioConnection          patchCord18(PRE_DELAY_mixer, DELAY);
AudioConnection          patchCord19(PRE_DELAY_filter, 0, DELAY_mixer, 0);
AudioConnection          patchCord20(PRE_DELAY_filter, 0, PRE_DELAY_mixer, 0);
AudioConnection          patchCord21(VCA_env, PRE_DELAY_filter);
AudioConnection          patchCord22(VCF_HILOMID_mixer, 0, VCA, 0);
AudioConnection          patchCord23(DELAY, 0, DELAY_mixer, 1);
AudioConnection          patchCord24(DELAY, 0, PRE_DELAY_mixer, 1);
AudioConnection          patchCord25(DELAY, 1, DELAY_mixer, 2);
AudioConnection          patchCord26(DELAY, 2, DELAY_mixer, 3);
AudioConnection          patchCord27(VOL_dc_lvl, 0, VOL, 1);
AudioConnection          patchCord28(OUT_low_pass, 0, VOL, 0);
AudioConnection          patchCord29(DELAY_mixer, OUT_low_pass);
AudioConnection          patchCord30(VOL, 0, AUDIO_out, 0);
AudioConnection          patchCord31(VOL, 0, AUDIO_out, 1);
// GUItool: end automatically generated code


