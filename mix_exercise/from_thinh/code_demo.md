# Question 1:

## Test case 1

    input n: 10
    array: 19 32 40 50 58 59 64 88 95 100
    input x: 47
    true
    array after: 19 32 40 47 50 58 59 64 88 95 100

## Test case 2

    input n: 10
    array: 0 28 32 34 46 48 57 81 91 92
    input x: 60
    true
    array after: 0 28 32 34 46 48 57 60 81 91 92

## Test case 3

    input n: 5
    2
    5
    7
    10
    11
    array: 2 5 7 10 11
    input x: 5
    false
    array after: 2 5 7 10 11

# Question 2:

## Test case 1

    input:   i  am programmer
    --------------------------------------
    INPUT: '  i  am programmer  ' input length: 20
    OUTPUT: 'i am programmer' output length: 15

## Test case 2

    input:    i   am thinking    out   of   the   box
    --------------------------------------
    INPUT: '   i   am thinking    out   of   the   box   ' input length: 45
    OUTPUT: 'i am thinking out of the box' output length: 28

&nbsp;

# Question 3:

## debug test 1

    input: 56 65 74 100 99 68 86 180 90

    Input string: 56 65 74 100 99 68 86 180 90

    Processing ===============>
    RemoveExtraSpaces:
    56 65 74 100 99 68 86 180 90
    calculate weight:
    56 11 0  65 11 0  74 11 0  100 1 0  99 18 0  68 14 0  86 14 0  180 9 0  90 9 0
    sort up according to weight and count the weight occurrences:
    100 1 1  180 9 2  90 9 2  56 11 3  65 11 3  74 11 3  68 14 2  86 14 2  99 18 1
    print out weight occurrences > 1:
    9 9 11 11 11 14 14
    identify the groups needed to be sorted alphabetically:
    9 11 14
    sort the group that has weight=9
    180 1 0  90 9 0
    sort the group that has weight=11
    56 5 0  65 6 0  74 7 0
    sort the group that has weight=14
    68 6 0  86 8 0
    Done!
    100 1 1  180 9 2  90 9 2  56 11 3  65 11 3  74 11 3  68 14 2  86 14 2  99 18 1
    Finished, thank you! ================================

    Final String: 100 180 90 56 65 74 68 86 99

## debug test 2

    input:     108  90   504    450     23  302 230  10

    Input string:     108  90   504    450     23  302 230  10

    Processing ===============>
    RemoveExtraSpaces:
    108 90 504 450 23 302 230 10
    calculate weight:
    108 9 0  90 9 0  504 9 0  450 9 0  23 5 0  302 5 0  230 5 0  10 1 0
    sort up according to weight and count the weight occurrences:
    10 1 1  23 5 3  302 5 3  230 5 3  108 9 4  90 9 4  504 9 4  450 9 4
    print out weight occurrences > 1:
    5 5 5 9 9 9 9
    identify the groups needed to be sorted alphabetically:
    5 9
    sort the group that has weight=5
    23 2 0  230 2 0  302 3 0
    sort the group that has weight=9
    108 1 0  450 4 0  504 5 0  90 9 0
    Done!
    10 1 1  23 5 3  230 5 3  302 5 3  108 9 4  450 9 4  504 9 4  90 9 4
    Finished, thank you! ================================

    Final String: 10 23 230 302 108 450 504 90

## debug test 3

    input:

    Input string:

    Processing ===============>
    RemoveExtraSpaces:

    calculate weight:

    sort up according to weight and count the weight occurrences:

    print out weight occurrences > 1:

    identify the groups needed to be sorted alphabetically:

    Done!

    Finished, thank you! ================================

    Final String:

## Test case 1

    input:    23    401   140   21    102  29   410
    102 21 140 23 401 410 29

## Test case 2

    input:   85   97  6   28  73 25 13 5   89  72  55 63 24 92   88 10
    10 13 5 24 6 25 63 72 28 55 73 92 85 88 97 89

## _debug Test case 2_

    input:    85   97  6   28  73 25 13 5   89  72  55 63 24 92   88 10

    Input string:    85   97  6   28  73 25 13 5   89  72  55 63 24 92   88 10

    Processing ===============>
    RemoveExtraSpaces:
    85 97 6 28 73 25 13 5 89 72 55 63 24 92 88 10
    calculate weight:
    85 13 0  97 16 0  6 6 0  28 10 0  73 10 0  25 7 0  13 4 0  5 5 0  89 17 0  72 9 0  55 10 0  63 9 0  24 6 0  92 11
    0  88 16 0  10 1 0
    sort up according to weight and count the weight occurrences:
    10 1 1  13 4 1  5 5 1  6 6 2  24 6 2  25 7 1  72 9 2  63 9 2  28 10 3  73 10 3  55 10 3  92 11 1  85 13 1  97 16 2  88 16 2  89 17 1
    print out weight occurrences > 1:
    6 6 9 9 10 10 10 16 16
    identify the groups needed to be sorted alphabetically:
    6 9 10 16
    sort the group that has weight=6
    24 2 0  6 6 0
    sort the group that has weight=9
    63 6 0  72 7 0
    sort the group that has weight=10
    28 2 0  55 5 0  73 7 0
    sort the group that has weight=16
    88 8 0  97 9 0
    Done!
    10 1 1  13 4 1  5 5 1  24 6 2  6 6 2  25 7 1  63 9 2  72 9 2  28 10 3  55 10 3  73 10 3  92 11 1  85 13 1  88 16 2  97 16 2  89 17 1
    Finished, thank you! ================================

    Final String: 10 13 5 24 6 25 63 72 28 55 73 92 85 88 97 89
