// Copyright (c) 2019-2020 The Widecoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef WIDECOIN_INDEX_DISKTXPOS_H
#define WIDECOIN_INDEX_DISKTXPOS_H

#include <flatfile.h>
#include <serialize.h>

struct CDiskTxPos : public FlatFilePos
{
    unsigned int nTxOffset{0}; // after header

    SERIALIZE_METHODS(CDiskTxPos, obj)
    {
        READWRITEAS(FlatFilePos, obj);
        READWRITE(VARINT(obj.nTxOffset));
    }

    CDiskTxPos(const FlatFilePos &blockIn, unsigned int nTxOffsetIn) : FlatFilePos(blockIn.nFile, blockIn.nPos), nTxOffset(nTxOffsetIn) {
    }

    CDiskTxPos() {}
};

#endif // WIDECOIN_INDEX_DISKTXPOS_H
