// Copyright 2023
#ifndef STR_INSTRUMENTH
#define STR_INSTRUMENTH

#include "Instrument.h"

class StringInstrument : public Instrument
{
    // TODO: Declare private data members: numStrings, numFrets, isBowed
private:
    int numStrings;
    int numFrets;
    bool isBowed;

public:
    // TODO: Declare mutator functions -
    //      SetNumOfStrings(), SetNumOfFrets(), SetIsBowed()
    void SetNumOfStrings(int strings);

    void SetNumOfFrets(int frets);

    void SetIsBowed(bool bowed);

    // TODO: Declare accessor functions -
    //      GetNumOfStrings(), GetNumOfFrets(), GetIsBowed()
    int GetNumOfStrings() const;

    int GetNumOfFrets() const;

    bool GetIsBowed() const;
};

#endif
