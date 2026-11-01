# nkxxll home row mods for ErgoDox EZ

Copied from `nkxxll_base_ez`. Existing layers and thumb Shift are preserved.

| Tap | S | D | F | J | K | L |
| --- | --- | --- | --- | --- | --- | --- |
| Hold | Left GUI | Left Alt | Left Ctrl | Right Ctrl | Right Alt | Right GUI |

A and semicolon remain plain keys. Right Alt is AltGr on layouts that use it.

Tapping term: 230 ms. Chordal Hold: enabled, with explicit hand positions.
Flow Tap: 150 ms. Permissive Hold and Hold on Other Key Press: disabled.
Quick Tap remains 0 ms as in the original.

Hold a modifier for 230 ms before typing its shortcut. Same-hand chords are
settled as taps before the tapping term; Chordal Hold does not restrict holds
after the timeout. Flow Tap favors letters during fast typing.
These timing settings also apply to the existing thumb mod-taps.

Build: `qmk compile -kb ergodox_ez/base -km nkxxll_hrm_ez`

The copied default*.png.md files describe the inherited layout and do not show
the new home row modifiers.
