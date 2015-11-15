project information
-------------------

 this repository contains my implementation of the next kata
 (the long standing Soundex algorithm) in C++.
 
 The long-standing Soundex algorithms 
 encodes word into a letter
 plus three digits, mapping similarly sounding word to the same encodings.

 Here are the rules for Soundex, per Wikipedia:
 (http://en.wikipedia.org/wiki/Soundex) 

 *  Retain the first letter. 
    Drop all other occurrences of a, e, i, o, u, y, h, w.

 *  Replace consonants with digits (after the first letter):
     
     b, f, p, v: 1

     c, g, j, k, q, s, x, z: 2

     d, t: 3

     l: 4

     m, n: 5

     r: 6

 * If two adjacent letters encode to the same number, encode them instead
   as a single number. Also, do so if two letters with the same number are
   separated by "h" or "w" (but code them twice if separated by a vowel).
   This rule also applies to the first letter.

 * Stop when you have a letter and three digits. Zero-pad if needed.


installation and configuration
------------------------------

 Simply copy (clone the repository) and see and read it.


basic usage
-----------
 
 for gitlab

 `$ git clone https://gitlab.com/katas/soundex_algorithm_c_plus_plus.git`

 for github

 `$ git clone
 https://github.com/ordinary-developer/kata_soundex_algorithm_c_plus_plus.git'


license
-------

 This project is offered under the MIT license


contributing
------------

 This project doesn't need to be contributed.

 But just in case you can always connect with me.
