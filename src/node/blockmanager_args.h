
// Copyright (c) 2023 The Widecoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef WIDECOIN_NODE_BLOCKMANAGER_ARGS_H
#define WIDECOIN_NODE_BLOCKMANAGER_ARGS_H

#include <node/blockstorage.h>
#include <util/result.h>

class ArgsManager;

namespace node {
[[nodiscard]] util::Result<void> ApplyArgsManOptions(const ArgsManager& args, BlockManager::Options& opts);
} // namespace node

#endif // WIDECOIN_NODE_BLOCKMANAGER_ARGS_H
