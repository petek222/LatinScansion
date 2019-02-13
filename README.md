# LatinScansion
In-Development Application to scan Meter of Classical Latin Poetry (Dactylic Hexameter)

This program will allow the user to input a line of Latin Poetry, whose metrical pattern follows Dactlyic Hexameter 
(Although the selectivity of this meter will expand as development progresses.) 

Scanning is a task for every Classics student, and is often a difficult one. This application aims to expedite and check the
scansion process so that students may see the meter quickly, and begin to analyze its metrical and poetic constructs in the 
context of the larger Latin narrative of tranlsation. This will simplify the metric analysis of some of Rome's greatest writers,
including Vergil, Horace, Juvenal, Catullus, etc. 

This is a stepwise execution program, and (will) replicate the process of student scansion following the outline below:

NOTE: Latin Dactylic Hexameter is composed of 6 feet. Each foot is a collection of syllables, and are either: 
A.) DACTYLS ( - ˘	˘), or long-short-short
B.) SPONDEES (- -), or long-long

1.) All elisions will be marked and taken care of (not that the rare device of hiatus is not accounted for in this current 
software implemenation). DONE

2.) Of the six metrical feet, two will be promptly marked (the 6th as a spondee (long-long or long-short, but difference is 
negligable), the 5th as a dactyl (rarity of 5th-foot spondee is minute), and the first syllable as a long.) DONE

3.) All diphthongs and double-consonantal vowels marked as long. DONE

4.) Inflected endings based on declensions 1-5 of Latin marked as best as is possible. This will be done via a footCount, optimization algorithm (TBD). 

5.) Filling in the remaining syllable metrics as fits the dactylic meter progression. (Tied in with process of #4)

The result will be a fully-scanned line of dactylic hexameter Latin Verse. 
Note: Addition of Main Caesura may be added after full scansion dev is finished. 

The provided files include .h and .cpp files for the LatinScansion class that will be performing the scansion, as well as a
LatinScansionDriver.cpp that will maintain a main execution branch for the class.

The ambition is to eventually implement this into an iOS app using Objective-C/Swift for the
app store, for greater consumption and use in high-school Latin courses. The Application will also hopefully include declension/verbal conjugation references, and a step-by-step output of scansion process for better instruction. If you are interested in contributing to this project, contact me. Also feel free to pull/push code as desired if you write
something that could help.

“forsan et haec olim meminisse iuvabit." -Vergil 
