// Copyright (c) 2023 Widecoin Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "logprintf.h"

#include <clang-tidy/ClangTidyModule.h>
#include <clang-tidy/ClangTidyModuleRegistry.h>

class WidecoinModule final : public clang::tidy::ClangTidyModule
{
public:
    void addCheckFactories(clang::tidy::ClangTidyCheckFactories& CheckFactories) override
    {
        CheckFactories.registerCheck<widecoin::LogPrintfCheck>("widecoin-unterminated-logprintf");
    }
};

static clang::tidy::ClangTidyModuleRegistry::Add<WidecoinModule>
    X("widecoin-module", "Adds widecoin checks.");

volatile int WidecoinModuleAnchorSource = 0;
