# Asked by Quora

## Question

`Word sense disambiguation is the problem of determining which sense a word takes on in a particular setting, if that word has multiple meanings. For example, in the sentence "I went to get money from the bank", bank probably means the place where people deposit money, not the land beside a river or lake.`

`Suppose you are given a list of meanings for several words, formatted like so:`

    {
        "word_1": ["meaning one", "meaning two", ...],
        ...
        "word_n": ["meaning one", "meaning two", ...]
    }
`Given a sentence, most of whose words are contained in the meaning list above, create an algorithm that determines the likely sense of each possibly ambiguous word.`
