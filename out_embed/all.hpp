#pragma once

#include <string>
#include <unordered_map>

#include <saucer/webview.hpp>

#include "index.html.hpp"

namespace saucer::embedded
{
    inline auto all()
    {
        std::unordered_map<std::string, embedded_file> rtn;

        rtn.emplace("index.html", embedded_file{saucer::stash<>::view(f1Dqesn4NxFvpVB4P1U5D6IgLugdGaqMvuMcidTvXLCgieH9Dg), "text/html"});

        return rtn;
    }
} // namespace saucer::embedded
