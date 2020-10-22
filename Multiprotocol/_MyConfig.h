/*
   This file is meant to keep your settings after an upgrade of the multi source.
   If you know parameters you want for sure to be enabled or disabled in future
   then just force their values here.
   To enable  a setting use #define <setting name>
   To disable a setting use #undef  <setting name>
*/

// For example you can also define multiple module configurations, uncomment the one you want to compile for:
//DIY Multiprotocol for Lite Radio 2 with LCD, using NRF24L01 and CC2500 chips
#define Module_1
//DIY Multiprotocol for Lite Radio 2 without LCD, using NRF24L01 and CC2500 chips
//#define Module_2
//DIY external multiprotocol (PPM) with only an NRF24L01
//#define Module_3
//Regular JP 4-in-1 module
//#define Module_4

//Example on how to force the same ID for all modules: be carefull this is really if you want to be able to use one or another radio but not both!
//#define FORCE_GLOBAL_ID	0x12345678

#if defined Module_1
  //DIY Multiprotocol for Lite Radio 2 with LCD, using NRF24L01 and CC2500 chips
  // No need to define LITERADIO2 because it is essentially a full featured Radio now

  // Most STM32 development boards use the STM32F103C8T6, which has 64kb flash size
  // MPM now has a check for this and will disable the module unless you add this define:
  #define DISABLE_FLASH_SIZE_CHECK
  // If you are lucky, your development board will have the STM32F103CBT6 with 128kb flash
  // Otherwise its safest to undef protocols and options until your flash size is UNDER 50% flash size (60kb or so)

  // If Bayang is being used with Silverware whoops, define either of the following
  // depending on what TX option the whoops are compiled with and then fill out the
  // channel mapping below.
  #define SILVERWARE_USE_DEVO
  //#define SILVERWARE_USE_MULTI

  #ifdef SILVERWARE_USE_DEVO
    #undef CH5_SW
    #undef CH6_SW
    #undef CH10_SW
    #undef CH11_SW
    #undef CH12_SW
    #undef CH13_SW
    #define CH5_SW (Channel_AUX & _BV(1))
    #define CH6_SW (Channel_AUX & _BV(5))
    #define CH10_SW (Channel_AUX & _BV(0))
    #define CH11_SW (Channel_data[CH13]>CHANNEL_SWITCH)
    #define CH12_SW (Channel_AUX & _BV(6))
    #define CH13_SW (Channel_AUX & _BV(7))
  #elif SILVERWARE_USE_MULTI
    // Leave the channels as-is
  #endif

  #undef A7105_INSTALLED
  #undef CYRF6936_INSTALLED

//The protocols below need an A7105 to be installed
  #undef AFHDS2A_A7105_INO
  #undef AFHDS2A_RX_A7105_INO
  #undef BUGS_A7105_INO
  #undef FLYSKY_A7105_INO
  #undef FLYZONE_A7105_INO
  #undef HUBSAN_A7105_INO
  #undef PELIKAN_A7105_INO

//The protocols below need a CYRF6936 to be installed
  #undef DEVO_CYRF6936_INO
  #undef DSM_CYRF6936_INO
  #undef DSM_RX_CYRF6936_INO
  #undef J6PRO_CYRF6936_INO
  #undef TRAXXAS_CYRF6936_INO
  #undef WFLY_CYRF6936_INO
  #undef WK2x01_CYRF6936_INO

// Leaving the following protocols
////The protocols below need a CC2500 to be installed
//#define	CORONA_CC2500_INO
//#define	ESKY150V2_CC2500_INO	//Need both CC2500 and NRF
//#define	FRSKYL_CC2500_INO
//#define	FRSKYD_CC2500_INO
//#define	FRSKYV_CC2500_INO
//#define	FRSKYX_CC2500_INO
//#define	FRSKY_RX_CC2500_INO
//#define	HITEC_CC2500_INO
//#define	HOTT_CC2500_INO
//#define	OMP_CC2500_INO			//Need both CC2500 and NRF
//#define	SCANNER_CC2500_INO
//#define	SFHSS_CC2500_INO
//#define	SKYARTEC_CC2500_INO
//#define	REDPINE_CC2500_INO
//#define	RLINK_CC2500_INO

//All NRF protocols available
//The protocols below need a NRF24L01 to be installed
//#define	ASSAN_NRF24L01_INO
//#define	BAYANG_NRF24L01_INO
//#define	BAYANG_RX_NRF24L01_INO
//#define	BUGSMINI_NRF24L01_INO
//#define	CABELL_NRF24L01_INO
//#define	CFLIE_NRF24L01_INO
//#define	CG023_NRF24L01_INO
//#define	CX10_NRF24L01_INO		 //Include Q2X2 protocol
//#define	DM002_NRF24L01_INO
//#define	E01X_NRF24L01_INO
//#define	ESKY_NRF24L01_INO
//#define	ESKY150_NRF24L01_INO
//#define	FQ777_NRF24L01_INO
//#define	FX816_NRF24L01_INO
//#define	FY326_NRF24L01_INO
//#define	GD00X_NRF24L01_INO
//#define	GW008_NRF24L01_INO
//#define	HISKY_NRF24L01_INO
//#define	HONTAI_NRF24L01_INO
//#define	H8_3D_NRF24L01_INO
//#define	JJRC345_NRF24L01_INO
//#define	KF606_NRF24L01_INO
//#define	KN_NRF24L01_INO
//#define	MJXQ_NRF24L01_INO
//#define	MT99XX_NRF24L01_INO
//#define	NCC1701_NRF24L01_INO
//#define	POTENSIC_NRF24L01_INO
//#define	PROPEL_NRF24L01_INO
//#define	Q303_NRF24L01_INO
//#define	Q90C_NRF24L01_INO
//#define	REALACC_NRF24L01_INO
//#define	SHENQI_NRF24L01_INO
//#define	SLT_NRF24L01_INO
//#define	SYMAX_NRF24L01_INO
//#define	TIGER_NRF24L01_INO
//#define	V2X2_NRF24L01_INO
//#define	V761_NRF24L01_INO
//#define	V911S_NRF24L01_INO
//#define	XK_NRF24L01_INO
//#define	YD717_NRF24L01_INO
//#define	ZSX_NRF24L01_INO

//The protocols below need a SX1276 to be installed
  #undef FRSKYR9_SX1276_INO

//  #undef CHECK_FOR_BOOTLOADER
//  #undef ENABLE_PPM
  //#undef TELEMETRY
  #define BLUETOOTHTELEMETRY
  #undef INVERT_TELEMETRY
  //For STM32 and OrangeRX modules, comment to prevent the TX from forcing the serial telemetry polarity normal/invert.
  #undef INVERT_TELEMETRY_TX

#elif defined Module_2
  //DIY Multiprotocol for Lite Radio 2 without LCD, using NRF24L01 and CC2500 chips
  #define LITERADIO2

  // If Bayang is being used with Silverware whoops, define either of the following
  // depending on what TX option the whoops are compiled with and then fill out the
  // channel mapping below.
  #define SILVERWARE_USE_DEVO
  //#define SILVERWARE_USE_MULTI

  // ######### Channel Mapping for Silverware ############
  // This is where you map switch positions to Silverware channels. Normally this
  // can be done from your model configuration in the TX, but on the Lite Radio we
  // cannot switch models in on the TX, so you have to share the channel mapping with
  // the other modules.
  // if you are using USE_MULTI, channel 11 (on) disables high rates on the TX side,
  // nothing is received by the quad.
  // if you are using USE_DEVO, channel 13 is not received.
  // Examples
  // #define CHAN_5 UP(SwitchA)
  // - CHAN_5 is active when SwitchA is UP
  //
  // More complex
  // #define CHAN_6 DOWN(SwitchB) || MIDDLE(SwitchB)
  // - CHAN_6 is active when SwitchB is in the DOWN position OR the MIDDLE position
  //
  // Using multiple switches to send one channel:
  // #define CHAN_12 DOWN(SwitchA) && DOWN(SwitchD)
  // - CHAN_12 is active when both SwitchA and SwitchD are in the DOWN position
  //
  // Always send channel as active:
  // #define CHAN_6 true
  //
  // Never send channel/not used:
  // #define CHAN_12 false
  //
  #define CHAN_5 UP(SwitchA)
  #define CHAN_6 DOWN(SwitchB) || MIDDLE(SwitchB)
  #define CHAN_7 UP(SwitchD)
  #define CHAN_8 MIDDLE(SwitchB)
  #define CHAN_9 DOWN(SwitchC)
  #define CHAN_10 UP(SwitchC)
  #define CHAN_11 UP(SwitchB) || MIDDLE(SwitchB)
  #define CHAN_12 OFF // always off
  #define CHAN_13 OFF // always off

  // ######### Default TX Aux Switch to Channel Map ##########
  #define SwitchA CH5
  #define SwitchB CH6
  #define SwitchC CH7
  #define SwitchD CH8

  #define UP(ch) (Channel_data[ch] > CHANNEL_MAX_COMMAND)
  #define MIDDLE(ch) (CHANNEL_MIN_COMMAND < Channel_data[ch] && Channel_data[ch] < CHANNEL_MAX_COMMAND)
  #define DOWN(ch) (Channel_data[ch] < CHANNEL_MIN_COMMAND)
  #define ON true
  #define OFF false

  #ifdef SILVERWARE_USE_DEVO
    #undef CH5_SW
    #undef CH6_SW
    #undef CH7_SW
    #undef CH8_SW
    #undef CH9_SW
    #undef CH10_SW
    #undef CH11_SW
    #undef CH12_SW
    #undef CH13_SW
    #define CH5_SW (CHAN_6)
    #define CH6_SW (CHAN_10)
    #define CH7_SW (CHAN_7)
    #define CH8_SW (CHAN_8)
    #define CH9_SW (CHAN_9)
    #define CH10_SW (CHAN_5)
    #define CH11_SW (CHAN_13)
    #define CH12_SW (CHAN_11)
    #define CH13_SW (CHAN_12)
  #elif SILVERWARE_USE_MULTI
    #undef CH5_SW
    #undef CH6_SW
    #undef CH7_SW
    #undef CH8_SW
    #undef CH9_SW
    #undef CH10_SW
    #undef CH11_SW
    #undef CH12_SW
    #undef CH13_SW
    #define CH5_SW (CHAN_5)
    #define CH6_SW (CHAN_6)
    #define CH7_SW (CHAN_7)
    #define CH8_SW (CHAN_8)
    #define CH9_SW (CHAN_9)
    #define CH10_SW (CHAN_10)
    #define CH11_SW (CHAN_11)
    #define CH12_SW (CHAN_12)
    #define CH13_SW (CHAN_13)
  #endif

  #undef A7105_INSTALLED
  #undef CYRF6936_INSTALLED

//The protocols below need an A7105 to be installed
  #undef AFHDS2A_A7105_INO
  #undef AFHDS2A_RX_A7105_INO
  #undef BUGS_A7105_INO
  #undef FLYSKY_A7105_INO
  #undef FLYZONE_A7105_INO
  #undef HUBSAN_A7105_INO
  #undef PELIKAN_A7105_INO

//The protocols below need a CYRF6936 to be installed
  #undef DEVO_CYRF6936_INO
  #undef DSM_CYRF6936_INO
  #undef DSM_RX_CYRF6936_INO
  #undef J6PRO_CYRF6936_INO
  #undef TRAXXAS_CYRF6936_INO
  #undef WFLY_CYRF6936_INO
  #undef WK2x01_CYRF6936_INO

//The protocols below need a CC2500 to be installed
//  #undef CORONA_CC2500_INO
//  #undef ESKY150V2_CC2500_INO  //Need both CC2500 and NRF
//  #undef FRSKYL_CC2500_INO
//  #undef FRSKYV_CC2500_INO
//  #undef HITEC_CC2500_INO
//  #undef HOTT_CC2500_INO
//  #undef SKYARTEC_CC2500_INO

// Leaving the following protocols
//#define FRSKYD_CC2500_INO
//#define FRSKYX_CC2500_INO
//#define FRSKY_RX_CC2500_INO
//#define SCANNER_CC2500_INO
//#define SFHSS_CC2500_INO
//#define REDPINE_CC2500_INO

//The protocols below need a NRF24L01 to be installed
//  #undef ASSAN_NRF24L01_INO
//  #undef BUGSMINI_NRF24L01_INO
//  #undef CABELL_NRF24L01_INO
//  #undef CFLIE_NRF24L01_INO
//  #undef CG023_NRF24L01_INO
//  #undef CX10_NRF24L01_INO    //Include Q2X2 protocol
//  #undef DM002_NRF24L01_INO
//  #undef ESKY_NRF24L01_INO
//  #undef ESKY150_NRF24L01_INO
//  #undef FQ777_NRF24L01_INO
//  #undef FX816_NRF24L01_INO
//  #undef FY326_NRF24L01_INO
//  #undef GD00X_NRF24L01_INO
//  #undef GW008_NRF24L01_INO
//  #undef HISKY_NRF24L01_INO
//  #undef HONTAI_NRF24L01_INO
//  #undef H8_3D_NRF24L01_INO
//  #undef JJRC345_NRF24L01_INO
//  #undef KF606_NRF24L01_INO
//  #undef KN_NRF24L01_INO
//  #undef MJXQ_NRF24L01_INO
//  #undef MT99XX_NRF24L01_INO
//  #undef NCC1701_NRF24L01_INO
//  #undef POTENSIC_NRF24L01_INO
//  #undef PROPEL_NRF24L01_INO
//  #undef Q303_NRF24L01_INO
//  #undef Q90C_NRF24L01_INO
//  #undef SHENQI_NRF24L01_INO
//  #undef SLT_NRF24L01_INO
//  #undef SYMAX_NRF24L01_INO
//  #undef TIGER_NRF24L01_INO
//  #undef V2X2_NRF24L01_INO
//  #undef V761_NRF24L01_INO
//  #undef V911S_NRF24L01_INO
//  #undef XK_NRF24L01_INO
//  #undef YD717_NRF24L01_INO
//  #undef ZSX_NRF24L01_INO
//
//Leaving the following protocols
//#define BAYANG_NRF24L01_INO
//#define BAYANG_RX_NRF24L01_INO
//#define E01X_NRF24L01_INO
//#define KF606_NRF24L01_INO

//The protocols below need a SX1276 to be installed
  #undef FRSKYR9_SX1276_INO

  //#undef CHECK_FOR_BOOTLOADER
  //#undef TELEMETRY
  #define BLUETOOTHTELEMETRY
  #undef INVERT_TELEMETRY
  //For STM32 and OrangeRX modules, comment to prevent the TX from forcing the serial telemetry polarity normal/invert.
  #undef INVERT_TELEMETRY_TX

  //Example of a module which will be PPM only with a different protocol table
  #undef ENABLE_SERIAL
  #undef NBR_BANKS
  #define NBR_BANKS 3   // redefine the number of banks
  #define MY_PPM_PROT   // Use the below protocol list. rotary dial fixed to 1, so change banks to select Frsky D8, Frsky X16 or Bayang
  const PPM_Parameters My_PPM_prot[14*NBR_BANKS]={
//******************************       BANK 1       ******************************
//  Switch  Protocol    Sub protocol  RX_Num  Power   Auto Bind   Option  Chan Order
/*  1 */  {PROTO_FRSKYD,  DCLONE    , 0 , P_HIGH  , NO_AUTOBIND , 0  , 0x00000000 }, // option=fine freq tuning
/*  1 */  {PROTO_FRSKYD,  FRSKYD    , 0 , P_HIGH  , NO_AUTOBIND , 40  , 0x00000000 }, // option=fine freq tuning
/*  2 */  {PROTO_FRSKYX,  CH_16   , 0 , P_HIGH  , NO_AUTOBIND , 40  , 0x00000000 }, // option=fine freq tuning
/*  3 */  {PROTO_BAYANG,  BAYANG    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  4 */  {PROTO_AFHDS2A, PWM_IBUS  , 2 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 }, // RX number 2
/*  5 */  {PROTO_AFHDS2A, PWM_IBUS  , 3 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 }, // RX number 3
/*  6 */  {PROTO_AFHDS2A, PWM_IBUS  , 2 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 }, // RX number 4
/*  7 */  {PROTO_AFHDS2A, PWM_IBUS  , 3 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 }, // RX number 5
/*  8 */  {PROTO_SFHSS, H107    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  9 */  {PROTO_FRSKYV,  NONE    , 0 , P_HIGH  , NO_AUTOBIND , 40  , 0x00000000 }, // option=fine freq tuning
/*  10 */  {PROTO_KN , WLTOYS    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  11  */  {PROTO_FRSKYX,  CH_16   , 0 , P_HIGH  , NO_AUTOBIND , 40  , 0x00000000 }, // option=fine freq tuning
/*  12  */  {PROTO_FRSKYX,  EU_16   , 0 , P_HIGH  , NO_AUTOBIND , 40  , 0x00000000 }, // option=fine freq tuning
/*  14  */  {PROTO_WK2x01,  WK2801    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
//******************************       BANK 2       ******************************
//  Switch  Protocol    Sub protocol  RX_Num  Power   Auto Bind   Option  Chan Order
/*  1 */  {PROTO_FRSKYD,  FRSKYD    , 0 , P_HIGH  , NO_AUTOBIND , 40  , 0x00000000 }, // option=fine freq tuning
/*  1 */  {PROTO_FRSKY_RX,  FRSKY_CLONE   , 0 , P_HIGH  , NO_AUTOBIND , 0  , 0x00000000 }, // option=fine freq tuning
/*  2 */  {PROTO_FRSKYX,  CH_16   , 0 , P_HIGH  , NO_AUTOBIND , 40  , 0x00000000 }, // option=fine freq tuning
/*  3 */  {PROTO_DSM  , DSM2_11   , 0 , P_HIGH  , NO_AUTOBIND , 6 , 0x00000000 }, // option=number of channels
/*  4 */  {PROTO_DSM  , DSM2_22   , 0 , P_HIGH  , NO_AUTOBIND , 6 , 0x00000000 }, // option=number of channels
/*  5 */  {PROTO_DSM  , DSMX_11   , 0 , P_HIGH  , NO_AUTOBIND , 6 , 0x00000000 }, // option=number of channels
/*  6 */  {PROTO_DSM  , DSMX_22   , 0 , P_HIGH  , NO_AUTOBIND , 6 , 0x00000000 }, // option=number of channels
/*  7 */  {PROTO_DSM  , DSM2_11   , 0 , P_HIGH  , NO_AUTOBIND , 8 , 0x00000000 }, // option=number of channels
/*  8 */  {PROTO_DSM  , DSM2_22   , 0 , P_HIGH  , NO_AUTOBIND , 8 , 0x00000000 }, // option=number of channels
/*  10  */  {PROTO_DSM  , DSMX_22   , 0 , P_HIGH  , NO_AUTOBIND , 8 , 0x00000000 }, // option=number of channels
/*  11  */  {PROTO_SLT  , SLT_V1    , 0 , P_HIGH  , NO_AUTOBIND , 6 , 0x00000000 },
/*  12  */  {PROTO_HUBSAN,  H107    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  13  */  {PROTO_HUBSAN,  H301    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  14  */  {PROTO_HUBSAN,  H501    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
//******************************       BANK 3       ******************************
//  Switch  Protocol    Sub protocol  RX_Num  Power   Auto Bind   Option  Chan Order
/*  1 */  {PROTO_BAYANG,  BAYANG    , 0 , P_HIGH  , NO_AUTOBIND , 1 , 0x00000000 },
/*  2 */  {PROTO_KF606,  NONE   , 0 , P_HIGH  , AUTOBIND , 0  , 0x00000000 }, // option=normal
/*  3 */  {PROTO_ASSAN, NONE    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  4 */  {PROTO_CORONA,  COR_V2    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  5 */  {PROTO_SYMAX, SYMAX   , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  6 */  {PROTO_KN , WLTOYS    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  7 */  {PROTO_ESKY , NONE    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  8 */  {PROTO_BAYANG,  H8S3D   , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  9 */  {PROTO_BAYANG,  X16_AH    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  10  */  {PROTO_BAYANG,  IRDRONE   , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  11  */  {PROTO_H8_3D, H8_3D   , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  12  */  {PROTO_H8_3D, H20H    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  13  */  {PROTO_H8_3D, H20MINI   , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  14  */  {PROTO_H8_3D, H30MINI   , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
  };

#elif defined Module_3
  #define FORCE_GLOBAL_ID  0xD53E4D27

  // If Bayang is being used with Silverware whoops, define either of the following
  // depending on what TX option the whoops are compiled with and then fill out the
  // channel mapping below.
  #define SILVERWARE_USE_DEVO
  //#define SILVERWARE_USE_MULTI

  // ######### Channel Mapping for Silverware ############
  // This is where you map switch positions to Silverware channels. Normally this
  // can be done from your model configuration in the TX, but on the Lite Radio we
  // cannot switch models in on the TX, so you have to share the channel mapping with
  // the other modules.
  // if you are using USE_MULTI, channel 11 (on) disables high rates on the TX side,
  // nothing is received by the quad.
  // if you are using USE_DEVO, channel 13 is not received.
  // Examples
  // #define CHAN_5 UP(SwitchA)
  // - CHAN_5 is active when SwitchA is UP
  //
  // More complex
  // #define CHAN_6 DOWN(SwitchB) || MIDDLE(SwitchB)
  // - CHAN_6 is active when SwitchB is in the DOWN position OR the MIDDLE position
  //
  // Using multiple switches to send one channel:
  // #define CHAN_12 DOWN(SwitchA) && DOWN(SwitchD)
  // - CHAN_12 is active when both SwitchA and SwitchD are in the DOWN position
  //
  // Always send channel as active:
  // #define CHAN_6 true
  //
  // Never send channel/not used:
  // #define CHAN_12 false
  //
  #define CHAN_5 UP(SwitchA)
  #define CHAN_6 DOWN(SwitchB) || MIDDLE(SwitchB)
  #define CHAN_7 UP(SwitchD)
  #define CHAN_8 MIDDLE(SwitchB)
  #define CHAN_9 DOWN(SwitchC)
  #define CHAN_10 UP(SwitchC)
  #define CHAN_11 UP(SwitchB) || MIDDLE(SwitchB)
  #define CHAN_12 OFF // always off
  #define CHAN_13 OFF // always off

  // ######### Default TX Aux Switch to Channel Map ##########
  #define SwitchA CH5
  #define SwitchB CH6
  #define SwitchC CH7
  #define SwitchD CH8

  #define UP(ch) (Channel_data[ch] > CHANNEL_MAX_COMMAND)
  #define MIDDLE(ch) (CHANNEL_MIN_COMMAND < Channel_data[ch] && Channel_data[ch] < CHANNEL_MAX_COMMAND)
  #define DOWN(ch) (Channel_data[ch] < CHANNEL_MIN_COMMAND)
  #define ON true
  #define OFF false

  #ifdef SILVERWARE_USE_DEVO
    #undef CH5_SW
    #undef CH6_SW
    #undef CH7_SW
    #undef CH8_SW
    #undef CH9_SW
    #undef CH10_SW
    #undef CH11_SW
    #undef CH12_SW
    #undef CH13_SW
    #define CH5_SW (CHAN_6)
    #define CH6_SW (CHAN_10)
    #define CH7_SW (CHAN_7)
    #define CH8_SW (CHAN_8)
    #define CH9_SW (CHAN_9)
    #define CH10_SW (CHAN_5)
    #define CH11_SW (CHAN_13)
    #define CH12_SW (CHAN_11)
    #define CH13_SW (CHAN_12)
  #elif SILVERWARE_USE_MULTI
    #undef CH5_SW
    #undef CH6_SW
    #undef CH7_SW
    #undef CH8_SW
    #undef CH9_SW
    #undef CH10_SW
    #undef CH11_SW
    #undef CH12_SW
    #undef CH13_SW
    #define CH5_SW (CHAN_5)
    #define CH6_SW (CHAN_6)
    #define CH7_SW (CHAN_7)
    #define CH8_SW (CHAN_8)
    #define CH9_SW (CHAN_9)
    #define CH10_SW (CHAN_10)
    #define CH11_SW (CHAN_11)
    #define CH12_SW (CHAN_12)
    #define CH13_SW (CHAN_13)
  #endif

  #undef A7105_INSTALLED
  #undef CYRF6936_INSTALLED
  #undef CC2500_INSTALLED

//The protocols below need an A7105 to be installed
  #undef AFHDS2A_A7105_INO
  #undef AFHDS2A_RX_A7105_INO
  #undef BUGS_A7105_INO
  #undef FLYSKY_A7105_INO
  #undef HEIGHT_A7105_INO
  #undef HUBSAN_A7105_INO
  #undef PELIKAN_A7105_INO
  #undef KYOSHO_A7105_INO

//The protocols below need a CYRF6936 to be installed
  #undef DEVO_CYRF6936_INO
  #undef DSM_CYRF6936_INO
  #undef DSM_RX_CYRF6936_INO
  #undef J6PRO_CYRF6936_INO
  #undef TRAXXAS_CYRF6936_INO
  #undef WFLY_CYRF6936_INO
  #undef WK2x01_CYRF6936_INO

//The protocols below need a CC2500 to be installed
  #undef CORONA_CC2500_INO
  #undef ESKY150V2_CC2500_INO  //Need both CC2500 and NRF
  #undef FRSKYL_CC2500_INO
  #undef FRSKYV_CC2500_INO
  #undef HITEC_CC2500_INO
  #undef HOTT_CC2500_INO
  #undef SKYARTEC_CC2500_INO
  #undef FRSKYD_CC2500_INO
  #undef FRSKYX_CC2500_INO
  #undef FRSKY_RX_CC2500_INO
  #undef SCANNER_CC2500_INO
  #undef SFHSS_CC2500_INO
  #undef REDPINE_CC2500_INO
  #undef RLINK_CC2500_INO

//Available Protocols
//#define ASSAN_NRF24L01_INO
//#define BAYANG_NRF24L01_INO
//#define BAYANG_RX_NRF24L01_INO
//#define BUGSMINI_NRF24L01_INO
//#define CABELL_NRF24L01_INO
//#define CFLIE_NRF24L01_INO
//#define CG023_NRF24L01_INO
//#define CX10_NRF24L01_INO    //Include Q2X2 protocol
//#define DM002_NRF24L01_INO
//#define E01X_NRF24L01_INO
//#define ESKY_NRF24L01_INO
//#define ESKY150_NRF24L01_INO
//#define FQ777_NRF24L01_INO
//#define FX816_NRF24L01_INO
//#define FY326_NRF24L01_INO
//#define GD00X_NRF24L01_INO
//#define GW008_NRF24L01_INO
//#define HISKY_NRF24L01_INO
//#define HONTAI_NRF24L01_INO
//#define H8_3D_NRF24L01_INO
//#define JJRC345_NRF24L01_INO
//#define KF606_NRF24L01_INO
//#define KN_NRF24L01_INO
//#define MJXQ_NRF24L01_INO
//#define MT99XX_NRF24L01_INO
//#define NCC1701_NRF24L01_INO
//#define POTENSIC_NRF24L01_INO
//#define PROPEL_NRF24L01_INO
//#define Q303_NRF24L01_INO
//#define Q90C_NRF24L01_INO
//#define SHENQI_NRF24L01_INO
//#define SLT_NRF24L01_INO
//#define SYMAX_NRF24L01_INO
//#define TIGER_NRF24L01_INO
//#define V2X2_NRF24L01_INO
//#define V761_NRF24L01_INO
//#define V911S_NRF24L01_INO
//#define XK_NRF24L01_INO
//#define YD717_NRF24L01_INO
//#define ZSX_NRF24L01_INO

//The protocols below need a SX1276 to be installed
  #undef FRSKYR9_SX1276_INO


  #undef CHECK_FOR_BOOTLOADER
  #undef TELEMETRY
  #undef ENABLE_SERIAL
  #undef NBR_BANKS
  #define NBR_BANKS 3   // redefine the number of banks
  #define MY_PPM_PROT   // Use the bellow protocol list
  const PPM_Parameters My_PPM_prot[14*NBR_BANKS]={
//******************************       BANK 1       ******************************
// Switch  Protocol    Sub protocol  RX_Num  Power   Auto Bind   Option  Chan Order
/*  7 */  {PROTO_BAYANG,  BAYANG    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  8 */  {PROTO_BAYANG,  H8S3D   , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  9 */  {PROTO_BAYANG,  X16_AH    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  4 */  {PROTO_AFHDS2A, PWM_IBUS  , 2 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 }, // RX number 2
/*  5 */  {PROTO_AFHDS2A, PWM_IBUS  , 3 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 }, // RX number 3
/*  6 */  {PROTO_AFHDS2A, PWM_IBUS  , 2 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 }, // RX number 4
/*  7 */  {PROTO_AFHDS2A, PWM_IBUS  , 3 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 }, // RX number 5
/*  8 */  {PROTO_SFHSS, H107    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  9 */  {PROTO_FRSKYV,  NONE    , 0 , P_HIGH  , NO_AUTOBIND , 40  , 0x00000000 }, // option=fine freq tuning
/*  10  */  {PROTO_FRSKYD,  NONE    , 0 , P_HIGH  , NO_AUTOBIND , 40  , 0x00000000 }, // option=fine freq tuning
/*  11  */  {PROTO_FRSKYX,  CH_16   , 0 , P_HIGH  , NO_AUTOBIND , 40  , 0x00000000 }, // option=fine freq tuning
/*  12  */  {PROTO_FRSKYX,  EU_16   , 0 , P_HIGH  , NO_AUTOBIND , 40  , 0x00000000 }, // option=fine freq tuning
/*  13  */  {PROTO_DEVO , NONE    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  14  */  {PROTO_WK2x01,  WK2801    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
//******************************       BANK 2       ******************************
//  Switch  Protocol    Sub protocol  RX_Num  Power   Auto Bind   Option  Chan Order
/*  1 */  {PROTO_DSM  , DSM2_11   , 0 , P_HIGH  , NO_AUTOBIND , 6 , 0x00000000 }, // option=number of channels
/*  2 */  {PROTO_DSM  , DSM2_22   , 0 , P_HIGH  , NO_AUTOBIND , 6 , 0x00000000 }, // option=number of channels
/*  3 */  {PROTO_DSM  , DSMX_11   , 0 , P_HIGH  , NO_AUTOBIND , 6 , 0x00000000 }, // option=number of channels
/*  4 */  {PROTO_DSM  , DSMX_22   , 0 , P_HIGH  , NO_AUTOBIND , 6 , 0x00000000 }, // option=number of channels
/*  5 */  {PROTO_DSM  , DSM2_11   , 0 , P_HIGH  , NO_AUTOBIND , 8 , 0x00000000 }, // option=number of channels
/*  6 */  {PROTO_DSM  , DSM2_22   , 0 , P_HIGH  , NO_AUTOBIND , 8 , 0x00000000 }, // option=number of channels
/*  7 */  {PROTO_DSM  , DSMX_11   , 0 , P_HIGH  , NO_AUTOBIND , 8 , 0x00000000 }, // option=number of channels
/*  8 */  {PROTO_DSM  , DSMX_22   , 0 , P_HIGH  , NO_AUTOBIND , 8 , 0x00000000 }, // option=number of channels
/*  9 */  {PROTO_SLT  , SLT_V1    , 0 , P_HIGH  , NO_AUTOBIND , 6 , 0x00000000 },
/*  10  */  {PROTO_HUBSAN,  H107    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  11  */  {PROTO_HUBSAN,  H301    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  12  */  {PROTO_HUBSAN,  H501    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  13  */  {PROTO_HISKY, Hisky   , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  14  */  {PROTO_V2X2 , NONE    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
//******************************       BANK 3       ******************************
//  Switch  Protocol    Sub protocol  RX_Num  Power   Auto Bind   Option  Chan Order
/*  1 */  {PROTO_KF606,  NONE   , 0 , P_HIGH  , AUTOBIND , 0  , 0x00000000 }, // option=normal
/*  2 */  {PROTO_KF606,  NONE   , 0 , P_HIGH  , AUTOBIND , 1  , 0x00000000 }, // option=use CC2500
/*  3 */  {PROTO_KF606,  NONE   , 0 , P_HIGH  , NO_AUTOBIND , 0  , 0x00000000 }, // option=normal
/*  4 */  {PROTO_KF606,  NONE   , 0 , P_HIGH  , NO_AUTOBIND , 1  , 0x00000000 }, // option=use CC2500
/*  5 */  {PROTO_SYMAX, SYMAX   , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  6 */  {PROTO_KN , WLTOYS    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  7 */  {PROTO_BAYANG,  BAYANG    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  8 */  {PROTO_BAYANG,  H8S3D   , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  9 */  {PROTO_BAYANG,  X16_AH    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  10  */  {PROTO_BAYANG,  IRDRONE   , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  11  */  {PROTO_H8_3D, H8_3D   , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  12  */  {PROTO_H8_3D, H20H    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  13  */  {PROTO_H8_3D, H20MINI   , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  14  */  {PROTO_XN297DUMP, 3   , 0 , P_HIGH  , NO_AUTOBIND , -1 , 0x00000000 },
//******************************       BANK 4       ******************************
//  Switch  Protocol    Sub protocol  RX_Num  Power   Auto Bind   Option  Chan Order
/*  1 */  {PROTO_MJXQ , WLH08   , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  2 */  {PROTO_MJXQ , X600    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  3 */  {PROTO_MJXQ , X800    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  4 */  {PROTO_MJXQ , H26D    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  5 */  {PROTO_MJXQ , E010    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  6 */  {PROTO_MJXQ , H26WH   , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  7 */  {PROTO_HONTAI,  HONTAI    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  8 */  {PROTO_HONTAI,  JJRCX1    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  9 */  {PROTO_HONTAI,  X5C1    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  10  */  {PROTO_HONTAI,  FQ777_951 , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  11  */  {PROTO_Q303 , Q303    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  12  */  {PROTO_Q303 , CX35    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  13  */  {PROTO_Q303 , CX10D   , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  14  */  {PROTO_Q303 , CX10WD    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
//******************************       BANK 5       ******************************
//  Switch  Protocol    Sub protocol  RX_Num  Power   Auto Bind   Option  Chan Order
/*  1 */  {PROTO_CX10 , CX10_GREEN  , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  2 */  {PROTO_CX10 , CX10_BLUE , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  3 */  {PROTO_CX10 , DM007   , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  4 */  {PROTO_CX10 , JC3015_1  , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  5 */  {PROTO_CX10 , JC3015_2  , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  6 */  {PROTO_CX10 , MK33041   , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  7 */  {PROTO_Q2X2 , Q222    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  8 */  {PROTO_Q2X2 , Q242    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  9 */  {PROTO_Q2X2 , Q282    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  10  */  {PROTO_CG023, CG023   , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  11  */  {PROTO_CG023, YD829   , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  12  */  {PROTO_FQ777, NONE    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  13  */  {PROTO_YD717, YD717   , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
/*  14  */  {PROTO_MT99XX,  MT99    , 0 , P_HIGH  , NO_AUTOBIND , 0 , 0x00000000 },
};


#elif defined Module_4
//Settings in _Config.h are fine
#endif
