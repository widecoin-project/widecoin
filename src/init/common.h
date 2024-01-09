// Copyright (c) 2021-2022 The Widecoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

//! @file
//! @brief Common init functions shared by widecoin-node, widecoin-wallet, etc.

#ifndef WIDECOIN_INIT_COMMON_H
#define WIDECOIN_INIT_COMMON_H

#include <util/result.h>

class ArgsManager;

namespace init {
void AddLoggingArgs(ArgsManager& args);
void SetLoggingOptions(const ArgsManager& args);
[[nodiscard]] util::Result<void> SetLoggingCategories(const ArgsManager& args);
[[nodiscard]] util::Result<void> SetLoggingLevel(const ArgsManager& args);
bool StartLogging(const ArgsManager& args);
void LogPackageVersion();
} // namespace init

#endif // WIDECOIN_INIT_COMMON_H
