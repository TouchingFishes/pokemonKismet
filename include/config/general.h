#ifndef GUARD_CONFIG_GENERAL_H
#define GUARD_CONFIG_GENERAL_H

// In the Generation 3 games, Asserts were used in various debug builds.
// Ruby/Sapphire and Emerald do not have these asserts while Fire Red
// still has them in the ROM. This is because the developers forgot
// to define NDEBUG before release, however this has been changed as
// Ruby's actual debug build does not use the AGBPrint features.
//
// Use `make release` to automatically enable NDEBUG.
#ifdef RELEASE
#define NDEBUG
#endif

// printf debugging is now enabled by default. This allows
// the various AGBPrint functions to be used. (See include/gba/isagbprint.h).
// See below for enabling different pretty printing versions.
// To disable printf debugging, build a release build using `make release`.

#ifndef NDEBUG

#define PRETTY_PRINT_MINI_PRINTF (0)
#define PRETTY_PRINT_LIBC (1)

#define LOG_HANDLER_AGB_PRINT (0)
#define LOG_HANDLER_NOCASH_PRINT (1)
#define LOG_HANDLER_MGBA_PRINT (2)

// Use this switch to choose a handler for pretty printing.
// NOTE: mini_printf supports a custom pretty printing formatter to display preproc encoded strings. (%S)
//       some libc distributions (especially dkp arm-libc) will fail to link pretty printing.
#define PRETTY_PRINT_HANDLER (PRETTY_PRINT_MINI_PRINTF)

// Use this switch to choose a handler for printf output.
// NOTE: These will only work on the respective emulators and should not be used in a productive environment.
//       Some emulators or real hardware might (and is allowed to) crash if they are used.
//       AGB_PRINT is supported on respective debug units.

#define LOG_HANDLER (LOG_HANDLER_MGBA_PRINT)
#endif

// Uncomment to fix some identified minor bugs
#define BUGFIX

// Various undefined behavior bugs may or may not prevent compilation with
// newer compilers. So always fix them when using a modern compiler.
#if MODERN || defined(BUGFIX)
#ifndef UBFIX
#define UBFIX
#endif
#endif

// Compatibility definition for other projects to detect pokeemerald-expansion
#define RHH_EXPANSION

// Legacy branch-based defines included for backwards compatibility
#define BATTLE_ENGINE
#define POKEMON_EXPANSION
#define ITEM_EXPANSION

// Generation constants used in configs to define behavior.
#define GEN_1 0
#define GEN_2 1
#define GEN_3 2
#define GEN_4 3
#define GEN_5 4
#define GEN_6 5
#define GEN_7 6
#define GEN_8 7
#define GEN_9 8
#define GEN_COUNT 9
// Changing GEN_LATEST's value to a different Generation will change every default setting that uses it at once.
#define GEN_LATEST GEN_9

// Kismet's own balance pass, selectable like a generation. Computed from GEN_COUNT
// rather than hardcoded, so it moves automatically if a generation is ever added -
// a literal would collide with GEN_10 the moment one exists. Properties relied on:
//   - sits above every real GEN_x, so all `>= GEN_x` tests stay true and expansion's
//     latest data remains the fallback for moves Kismet does not override;
//   - all `== GEN_x` tests stay false (they only ever target GEN_1..GEN_5);
//   - takes the first slot after overworld.h's GEN_6_ORAS / GEN_8_PLA / TIME_DEBUG
//     (GEN_COUNT + 1..+3), so no two sentinels ever share a number;
//   - fits the config bitfields in generational_changes.h, which size themselves
//     from this value via BIT_SIZE.
// Set a gate back to GEN_LATEST to get stock expansion behaviour for it.
#define CUSTOM_FOR_KISMET (GEN_COUNT + 4)

// General settings
#define EXPANSION_INTRO              TRUE    // If TRUE, a custom RHH intro will play after the vanilla copyright screen.
#define HQ_RANDOM                    TRUE    // If TRUE, replaces the default RNG with an implementation of SFC32 RNG. May break code that relies on RNG.
#define PHONEMES_SHARED              FALSE   // If TRUE, bard phonemes all reference the same sound (sound/direct_sound_samples/phonemes/shared.bin) to save ROM space.

// Measurement system constants to be used for UNITS
#define UNITS_IMPERIAL               0       // Inches, feet, pounds
#define UNITS_METRIC                 1       // meters, kilograms

#define UNITS                        UNITS_IMPERIAL
#define CHAR_DEC_SEPARATOR           CHAR_PERIOD // CHAR_PERIOD is used as a decimal separator only in the UK and the US. The rest of the world uses CHAR_COMMA.

// Naming Screen
#define AUTO_LOWERCASE_KEYBOARD      GEN_3  // Starting in GEN_6, after entering the first uppercase character, the keyboard switches to lowercase letters.

#endif // GUARD_CONFIG_GENERAL_H
