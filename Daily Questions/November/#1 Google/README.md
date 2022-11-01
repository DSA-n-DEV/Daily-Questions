# Asked by Google

## Question

`You are given an N by N matrix of random letters and a dictionary of words. Find the maximum number of words that can be packed on the board from the given dictionary.`

`A word is considered to be able to be packed on the board if:`

    - It can be found in the dictionary
    - It can be constructed from untaken letters by other words found so far on the board
    - The letters are adjacent to each other (vertically and horizontally, not diagonally).

`Each tile can be visited only once by any word.`

`For example, given the following dictionary:`

    { 'eat', 'rain', 'in', 'rat' }`

`and matrix:`

    [['e', 'a', 'n'],
    ['t', 't', 'i'],
    ['a', 'r', 'a']]`

`Your function should return 3, since we can make the words 'eat', 'in', and 'rat' without them touching each other. We could have alternatively made 'eat' and 'rain', but that would be incorrect since that's only 2 words.`
