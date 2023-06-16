// Copyright (c) 2022 The Widecoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef WIDECOIN_KERNEL_BLOCKMANAGER_OPTS_H
#define WIDECOIN_KERNEL_BLOCKMANAGER_OPTS_H

namespace kernel {

/**
 * An options struct for `BlockManager`, more ergonomically referred to as
 * `BlockManager::Options` due to the using-declaration in `BlockManager`.
 */
struct BlockManagerOpts {
    uint64_t prune_target{0};
};

} // namespace kernel

#endif // WIDECOIN_KERNEL_BLOCKMANAGER_OPTS_H
