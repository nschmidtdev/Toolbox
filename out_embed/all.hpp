#pragma once

#include <string>
#include <unordered_map>

#include <saucer/webview.hpp>

#include "card.html.hpp"
#include "index.html.hpp"

namespace saucer::embedded
{
    inline auto all()
    {
        std::unordered_map<std::string, embedded_file> rtn;

        rtn.emplace("card.html", embedded_file{saucer::stash<>::view(fIMvMxLtCtgaCyOWT9Sq2cpZQFAUlr60fpjd781IKV2QwoDk), "text/html"});
        rtn.emplace("index.html", embedded_file{saucer::stash<>::view(f1Dqesn4NxFvpVZNG4N54sqKwGMdL3bEomjcPeIDDbCgBnsxvo), "text/html"});

        return rtn;
    }
} // namespace saucer::embedded
