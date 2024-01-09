// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2022 The Widecoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef WIDECOIN_INIT_H
#define WIDECOIN_INIT_H

#include <any>
#include <memory>
#include <string>

//! Default value for -daemon option
static constexpr bool DEFAULT_DAEMON = false;
//! Default value for -daemonwait option
static constexpr bool DEFAULT_DAEMONWAIT = false;

class ArgsManager;
namespace interfaces {
struct BlockAndHeaderTipInfo;
}
namespace kernel {
struct Context;
}
namespace node {
struct NodeContext;
} // namespace node

/** Interrupt threads */
void Interrupt(node::NodeContext& node);
void Shutdown(node::NodeContext& node);
//!Initialize the logging infrastructure
void InitLogging(const ArgsManager& args);
//!Parameter interaction: change current parameters depending on various rules
void InitParameterInteraction(ArgsManager& args);

/** Initialize widecoin core: Basic context setup.
 *  @note This can be done before daemonization. Do not call Shutdown() if this function fails.
 *  @pre Parameters should be parsed and config file should be read.
 */
bool AppInitBasicSetup(const ArgsManager& args, std::atomic<int>& exit_status);
/**
 * Initialization: parameter interaction.
 * @note This can be done before daemonization. Do not call Shutdown() if this function fails.
 * @pre Parameters should be parsed and config file should be read, AppInitBasicSetup should have been called.
 */
bool AppInitParameterInteraction(const ArgsManager& args);
/**
 * Initialization sanity checks.
 * @note This can be done before daemonization. Do not call Shutdown() if this function fails.
 * @pre Parameters should be parsed and config file should be read, AppInitParameterInteraction should have been called.
 */
bool AppInitSanityChecks(const kernel::Context& kernel);
/**
 * Lock widecoin core data directory.
 * @note This should only be done after daemonization. Do not call Shutdown() if this function fails.
 * @pre Parameters should be parsed and config file should be read, AppInitSanityChecks should have been called.
 */
bool AppInitLockDataDirectory();
/**
 * Initialize node and wallet interface pointers. Has no prerequisites or side effects besides allocating memory.
 */
bool AppInitInterfaces(node::NodeContext& node);
/**
 * Widecoin core main initialization.
 * @note This should only be done after daemonization. Call Shutdown() if this function fails.
 * @pre Parameters should be parsed and config file should be read, AppInitLockDataDirectory should have been called.
 */
bool AppInitMain(node::NodeContext& node, interfaces::BlockAndHeaderTipInfo* tip_info = nullptr);

/**
 * Register all arguments with the ArgsManager
 */
void SetupServerArgs(ArgsManager& argsman);

/** Validates requirements to run the indexes and spawns each index initial sync thread */
bool StartIndexBackgroundSync(node::NodeContext& node);

#endif // WIDECOIN_INIT_H
