// Copyright 2023
#include "StringInstrument.h"

// TODO: Define mutator functions -
//      SetNumOfStrings(), SetNumOfFrets(), SetIsBowed()

void StringInstrument::SetNumOfStrings(int strings)
{
    numStrings = strings;
}

void StringInstrument::SetNumOfFrets(int frets)
{
    numFrets = frets;
}

void StringInstrument::SetIsBowed(bool bowed)
{
    isBowed = bowed;
}

// TODO: Define accessor functions -
//      GetNumOfStrings(), GetNumOfFrets(), GetIsBowed()

int StringInstrument::GetNumOfStrings() const
{
    return numStrings;
}

int StringInstrument::GetNumOfFrets() const
{
    return numFrets;
}

bool StringInstrument::GetIsBowed() const
{
    return isBowed;
}
