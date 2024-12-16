#pragma once

#include <string>
#include <unordered_map>

#include <saucer/webview.hpp>

#include "highlight/DIGESTS.md.hpp"
#include "highlight/es/core.js.hpp"
#include "highlight/es/core.min.js.hpp"
#include "highlight/es/highlight.js.hpp"
#include "highlight/es/highlight.min.js.hpp"
#include "highlight/es/languages/asciidoc.js.hpp"
#include "highlight/es/languages/asciidoc.min.js.hpp"
#include "highlight/es/languages/http.js.hpp"
#include "highlight/es/languages/http.min.js.hpp"
#include "highlight/es/languages/json.js.hpp"
#include "highlight/es/languages/json.min.js.hpp"
#include "highlight/es/languages/lua.js.hpp"
#include "highlight/es/languages/lua.min.js.hpp"
#include "highlight/es/languages/markdown.js.hpp"
#include "highlight/es/languages/markdown.min.js.hpp"
#include "highlight/es/languages/shell.js.hpp"
#include "highlight/es/languages/shell.min.js.hpp"
#include "highlight/es/languages/sql.js.hpp"
#include "highlight/es/languages/sql.min.js.hpp"
#include "highlight/es/languages/xml.js.hpp"
#include "highlight/es/languages/xml.min.js.hpp"
#include "highlight/es/package.json.hpp"
#include "highlight/highlight.js.hpp"
#include "highlight/highlight.min.js.hpp"
#include "highlight/languages/asciidoc.js.hpp"
#include "highlight/languages/asciidoc.min.js.hpp"
#include "highlight/languages/http.js.hpp"
#include "highlight/languages/http.min.js.hpp"
#include "highlight/languages/json.js.hpp"
#include "highlight/languages/json.min.js.hpp"
#include "highlight/languages/lua.js.hpp"
#include "highlight/languages/lua.min.js.hpp"
#include "highlight/languages/markdown.js.hpp"
#include "highlight/languages/markdown.min.js.hpp"
#include "highlight/languages/shell.js.hpp"
#include "highlight/languages/shell.min.js.hpp"
#include "highlight/languages/sql.js.hpp"
#include "highlight/languages/sql.min.js.hpp"
#include "highlight/languages/xml.js.hpp"
#include "highlight/languages/xml.min.js.hpp"
#include "highlight/package.json.hpp"
#include "highlight/README.md.hpp"
#include "highlight/styles/1c-light.css.hpp"
#include "highlight/styles/1c-light.min.css.hpp"
#include "highlight/styles/a11y-dark.css.hpp"
#include "highlight/styles/a11y-dark.min.css.hpp"
#include "highlight/styles/a11y-light.css.hpp"
#include "highlight/styles/a11y-light.min.css.hpp"
#include "highlight/styles/agate.css.hpp"
#include "highlight/styles/agate.min.css.hpp"
#include "highlight/styles/an-old-hope.css.hpp"
#include "highlight/styles/an-old-hope.min.css.hpp"
#include "highlight/styles/androidstudio.css.hpp"
#include "highlight/styles/androidstudio.min.css.hpp"
#include "highlight/styles/arduino-light.css.hpp"
#include "highlight/styles/arduino-light.min.css.hpp"
#include "highlight/styles/arta.css.hpp"
#include "highlight/styles/arta.min.css.hpp"
#include "highlight/styles/ascetic.css.hpp"
#include "highlight/styles/ascetic.min.css.hpp"
#include "highlight/styles/atom-one-dark-reasonable.css.hpp"
#include "highlight/styles/atom-one-dark-reasonable.min.css.hpp"
#include "highlight/styles/atom-one-dark.css.hpp"
#include "highlight/styles/atom-one-dark.min.css.hpp"
#include "highlight/styles/atom-one-light.css.hpp"
#include "highlight/styles/atom-one-light.min.css.hpp"
#include "highlight/styles/base16/3024.css.hpp"
#include "highlight/styles/base16/3024.min.css.hpp"
#include "highlight/styles/base16/apathy.css.hpp"
#include "highlight/styles/base16/apathy.min.css.hpp"
#include "highlight/styles/base16/apprentice.css.hpp"
#include "highlight/styles/base16/apprentice.min.css.hpp"
#include "highlight/styles/base16/ashes.css.hpp"
#include "highlight/styles/base16/ashes.min.css.hpp"
#include "highlight/styles/base16/atelier-cave-light.css.hpp"
#include "highlight/styles/base16/atelier-cave-light.min.css.hpp"
#include "highlight/styles/base16/atelier-cave.css.hpp"
#include "highlight/styles/base16/atelier-cave.min.css.hpp"
#include "highlight/styles/base16/atelier-dune-light.css.hpp"
#include "highlight/styles/base16/atelier-dune-light.min.css.hpp"
#include "highlight/styles/base16/atelier-dune.css.hpp"
#include "highlight/styles/base16/atelier-dune.min.css.hpp"
#include "highlight/styles/base16/atelier-estuary-light.css.hpp"
#include "highlight/styles/base16/atelier-estuary-light.min.css.hpp"
#include "highlight/styles/base16/atelier-estuary.css.hpp"
#include "highlight/styles/base16/atelier-estuary.min.css.hpp"
#include "highlight/styles/base16/atelier-forest-light.css.hpp"
#include "highlight/styles/base16/atelier-forest-light.min.css.hpp"
#include "highlight/styles/base16/atelier-forest.css.hpp"
#include "highlight/styles/base16/atelier-forest.min.css.hpp"
#include "highlight/styles/base16/atelier-heath-light.css.hpp"
#include "highlight/styles/base16/atelier-heath-light.min.css.hpp"
#include "highlight/styles/base16/atelier-heath.css.hpp"
#include "highlight/styles/base16/atelier-heath.min.css.hpp"
#include "highlight/styles/base16/atelier-lakeside-light.css.hpp"
#include "highlight/styles/base16/atelier-lakeside-light.min.css.hpp"
#include "highlight/styles/base16/atelier-lakeside.css.hpp"
#include "highlight/styles/base16/atelier-lakeside.min.css.hpp"
#include "highlight/styles/base16/atelier-plateau-light.css.hpp"
#include "highlight/styles/base16/atelier-plateau-light.min.css.hpp"
#include "highlight/styles/base16/atelier-plateau.css.hpp"
#include "highlight/styles/base16/atelier-plateau.min.css.hpp"
#include "highlight/styles/base16/atelier-savanna-light.css.hpp"
#include "highlight/styles/base16/atelier-savanna-light.min.css.hpp"
#include "highlight/styles/base16/atelier-savanna.css.hpp"
#include "highlight/styles/base16/atelier-savanna.min.css.hpp"
#include "highlight/styles/base16/atelier-seaside-light.css.hpp"
#include "highlight/styles/base16/atelier-seaside-light.min.css.hpp"
#include "highlight/styles/base16/atelier-seaside.css.hpp"
#include "highlight/styles/base16/atelier-seaside.min.css.hpp"
#include "highlight/styles/base16/atelier-sulphurpool-light.css.hpp"
#include "highlight/styles/base16/atelier-sulphurpool-light.min.css.hpp"
#include "highlight/styles/base16/atelier-sulphurpool.css.hpp"
#include "highlight/styles/base16/atelier-sulphurpool.min.css.hpp"
#include "highlight/styles/base16/atlas.css.hpp"
#include "highlight/styles/base16/atlas.min.css.hpp"
#include "highlight/styles/base16/bespin.css.hpp"
#include "highlight/styles/base16/bespin.min.css.hpp"
#include "highlight/styles/base16/black-metal-bathory.css.hpp"
#include "highlight/styles/base16/black-metal-bathory.min.css.hpp"
#include "highlight/styles/base16/black-metal-burzum.css.hpp"
#include "highlight/styles/base16/black-metal-burzum.min.css.hpp"
#include "highlight/styles/base16/black-metal-dark-funeral.css.hpp"
#include "highlight/styles/base16/black-metal-dark-funeral.min.css.hpp"
#include "highlight/styles/base16/black-metal-gorgoroth.css.hpp"
#include "highlight/styles/base16/black-metal-gorgoroth.min.css.hpp"
#include "highlight/styles/base16/black-metal-immortal.css.hpp"
#include "highlight/styles/base16/black-metal-immortal.min.css.hpp"
#include "highlight/styles/base16/black-metal-khold.css.hpp"
#include "highlight/styles/base16/black-metal-khold.min.css.hpp"
#include "highlight/styles/base16/black-metal-marduk.css.hpp"
#include "highlight/styles/base16/black-metal-marduk.min.css.hpp"
#include "highlight/styles/base16/black-metal-mayhem.css.hpp"
#include "highlight/styles/base16/black-metal-mayhem.min.css.hpp"
#include "highlight/styles/base16/black-metal-nile.css.hpp"
#include "highlight/styles/base16/black-metal-nile.min.css.hpp"
#include "highlight/styles/base16/black-metal-venom.css.hpp"
#include "highlight/styles/base16/black-metal-venom.min.css.hpp"
#include "highlight/styles/base16/black-metal.css.hpp"
#include "highlight/styles/base16/black-metal.min.css.hpp"
#include "highlight/styles/base16/brewer.css.hpp"
#include "highlight/styles/base16/brewer.min.css.hpp"
#include "highlight/styles/base16/bright.css.hpp"
#include "highlight/styles/base16/bright.min.css.hpp"
#include "highlight/styles/base16/brogrammer.css.hpp"
#include "highlight/styles/base16/brogrammer.min.css.hpp"
#include "highlight/styles/base16/brush-trees-dark.css.hpp"
#include "highlight/styles/base16/brush-trees-dark.min.css.hpp"
#include "highlight/styles/base16/brush-trees.css.hpp"
#include "highlight/styles/base16/brush-trees.min.css.hpp"
#include "highlight/styles/base16/chalk.css.hpp"
#include "highlight/styles/base16/chalk.min.css.hpp"
#include "highlight/styles/base16/circus.css.hpp"
#include "highlight/styles/base16/circus.min.css.hpp"
#include "highlight/styles/base16/classic-dark.css.hpp"
#include "highlight/styles/base16/classic-dark.min.css.hpp"
#include "highlight/styles/base16/classic-light.css.hpp"
#include "highlight/styles/base16/classic-light.min.css.hpp"
#include "highlight/styles/base16/codeschool.css.hpp"
#include "highlight/styles/base16/codeschool.min.css.hpp"
#include "highlight/styles/base16/colors.css.hpp"
#include "highlight/styles/base16/colors.min.css.hpp"
#include "highlight/styles/base16/cupcake.css.hpp"
#include "highlight/styles/base16/cupcake.min.css.hpp"
#include "highlight/styles/base16/cupertino.css.hpp"
#include "highlight/styles/base16/cupertino.min.css.hpp"
#include "highlight/styles/base16/danqing.css.hpp"
#include "highlight/styles/base16/danqing.min.css.hpp"
#include "highlight/styles/base16/darcula.css.hpp"
#include "highlight/styles/base16/darcula.min.css.hpp"
#include "highlight/styles/base16/dark-violet.css.hpp"
#include "highlight/styles/base16/dark-violet.min.css.hpp"
#include "highlight/styles/base16/darkmoss.css.hpp"
#include "highlight/styles/base16/darkmoss.min.css.hpp"
#include "highlight/styles/base16/darktooth.css.hpp"
#include "highlight/styles/base16/darktooth.min.css.hpp"
#include "highlight/styles/base16/decaf.css.hpp"
#include "highlight/styles/base16/decaf.min.css.hpp"
#include "highlight/styles/base16/default-dark.css.hpp"
#include "highlight/styles/base16/default-dark.min.css.hpp"
#include "highlight/styles/base16/default-light.css.hpp"
#include "highlight/styles/base16/default-light.min.css.hpp"
#include "highlight/styles/base16/dirtysea.css.hpp"
#include "highlight/styles/base16/dirtysea.min.css.hpp"
#include "highlight/styles/base16/dracula.css.hpp"
#include "highlight/styles/base16/dracula.min.css.hpp"
#include "highlight/styles/base16/edge-dark.css.hpp"
#include "highlight/styles/base16/edge-dark.min.css.hpp"
#include "highlight/styles/base16/edge-light.css.hpp"
#include "highlight/styles/base16/edge-light.min.css.hpp"
#include "highlight/styles/base16/eighties.css.hpp"
#include "highlight/styles/base16/eighties.min.css.hpp"
#include "highlight/styles/base16/embers.css.hpp"
#include "highlight/styles/base16/embers.min.css.hpp"
#include "highlight/styles/base16/equilibrium-dark.css.hpp"
#include "highlight/styles/base16/equilibrium-dark.min.css.hpp"
#include "highlight/styles/base16/equilibrium-gray-dark.css.hpp"
#include "highlight/styles/base16/equilibrium-gray-dark.min.css.hpp"
#include "highlight/styles/base16/equilibrium-gray-light.css.hpp"
#include "highlight/styles/base16/equilibrium-gray-light.min.css.hpp"
#include "highlight/styles/base16/equilibrium-light.css.hpp"
#include "highlight/styles/base16/equilibrium-light.min.css.hpp"
#include "highlight/styles/base16/espresso.css.hpp"
#include "highlight/styles/base16/espresso.min.css.hpp"
#include "highlight/styles/base16/eva-dim.css.hpp"
#include "highlight/styles/base16/eva-dim.min.css.hpp"
#include "highlight/styles/base16/eva.css.hpp"
#include "highlight/styles/base16/eva.min.css.hpp"
#include "highlight/styles/base16/flat.css.hpp"
#include "highlight/styles/base16/flat.min.css.hpp"
#include "highlight/styles/base16/framer.css.hpp"
#include "highlight/styles/base16/framer.min.css.hpp"
#include "highlight/styles/base16/fruit-soda.css.hpp"
#include "highlight/styles/base16/fruit-soda.min.css.hpp"
#include "highlight/styles/base16/gigavolt.css.hpp"
#include "highlight/styles/base16/gigavolt.min.css.hpp"
#include "highlight/styles/base16/github.css.hpp"
#include "highlight/styles/base16/github.min.css.hpp"
#include "highlight/styles/base16/google-dark.css.hpp"
#include "highlight/styles/base16/google-dark.min.css.hpp"
#include "highlight/styles/base16/google-light.css.hpp"
#include "highlight/styles/base16/google-light.min.css.hpp"
#include "highlight/styles/base16/grayscale-dark.css.hpp"
#include "highlight/styles/base16/grayscale-dark.min.css.hpp"
#include "highlight/styles/base16/grayscale-light.css.hpp"
#include "highlight/styles/base16/grayscale-light.min.css.hpp"
#include "highlight/styles/base16/green-screen.css.hpp"
#include "highlight/styles/base16/green-screen.min.css.hpp"
#include "highlight/styles/base16/gruvbox-dark-hard.css.hpp"
#include "highlight/styles/base16/gruvbox-dark-hard.min.css.hpp"
#include "highlight/styles/base16/gruvbox-dark-medium.css.hpp"
#include "highlight/styles/base16/gruvbox-dark-medium.min.css.hpp"
#include "highlight/styles/base16/gruvbox-dark-pale.css.hpp"
#include "highlight/styles/base16/gruvbox-dark-pale.min.css.hpp"
#include "highlight/styles/base16/gruvbox-dark-soft.css.hpp"
#include "highlight/styles/base16/gruvbox-dark-soft.min.css.hpp"
#include "highlight/styles/base16/gruvbox-light-hard.css.hpp"
#include "highlight/styles/base16/gruvbox-light-hard.min.css.hpp"
#include "highlight/styles/base16/gruvbox-light-medium.css.hpp"
#include "highlight/styles/base16/gruvbox-light-medium.min.css.hpp"
#include "highlight/styles/base16/gruvbox-light-soft.css.hpp"
#include "highlight/styles/base16/gruvbox-light-soft.min.css.hpp"
#include "highlight/styles/base16/hardcore.css.hpp"
#include "highlight/styles/base16/hardcore.min.css.hpp"
#include "highlight/styles/base16/harmonic16-dark.css.hpp"
#include "highlight/styles/base16/harmonic16-dark.min.css.hpp"
#include "highlight/styles/base16/harmonic16-light.css.hpp"
#include "highlight/styles/base16/harmonic16-light.min.css.hpp"
#include "highlight/styles/base16/heetch-dark.css.hpp"
#include "highlight/styles/base16/heetch-dark.min.css.hpp"
#include "highlight/styles/base16/heetch-light.css.hpp"
#include "highlight/styles/base16/heetch-light.min.css.hpp"
#include "highlight/styles/base16/helios.css.hpp"
#include "highlight/styles/base16/helios.min.css.hpp"
#include "highlight/styles/base16/hopscotch.css.hpp"
#include "highlight/styles/base16/hopscotch.min.css.hpp"
#include "highlight/styles/base16/horizon-dark.css.hpp"
#include "highlight/styles/base16/horizon-dark.min.css.hpp"
#include "highlight/styles/base16/horizon-light.css.hpp"
#include "highlight/styles/base16/horizon-light.min.css.hpp"
#include "highlight/styles/base16/humanoid-dark.css.hpp"
#include "highlight/styles/base16/humanoid-dark.min.css.hpp"
#include "highlight/styles/base16/humanoid-light.css.hpp"
#include "highlight/styles/base16/humanoid-light.min.css.hpp"
#include "highlight/styles/base16/ia-dark.css.hpp"
#include "highlight/styles/base16/ia-dark.min.css.hpp"
#include "highlight/styles/base16/ia-light.css.hpp"
#include "highlight/styles/base16/ia-light.min.css.hpp"
#include "highlight/styles/base16/icy-dark.css.hpp"
#include "highlight/styles/base16/icy-dark.min.css.hpp"
#include "highlight/styles/base16/ir-black.css.hpp"
#include "highlight/styles/base16/ir-black.min.css.hpp"
#include "highlight/styles/base16/isotope.css.hpp"
#include "highlight/styles/base16/isotope.min.css.hpp"
#include "highlight/styles/base16/kimber.css.hpp"
#include "highlight/styles/base16/kimber.min.css.hpp"
#include "highlight/styles/base16/london-tube.css.hpp"
#include "highlight/styles/base16/london-tube.min.css.hpp"
#include "highlight/styles/base16/macintosh.css.hpp"
#include "highlight/styles/base16/macintosh.min.css.hpp"
#include "highlight/styles/base16/marrakesh.css.hpp"
#include "highlight/styles/base16/marrakesh.min.css.hpp"
#include "highlight/styles/base16/materia.css.hpp"
#include "highlight/styles/base16/materia.min.css.hpp"
#include "highlight/styles/base16/material-darker.css.hpp"
#include "highlight/styles/base16/material-darker.min.css.hpp"
#include "highlight/styles/base16/material-lighter.css.hpp"
#include "highlight/styles/base16/material-lighter.min.css.hpp"
#include "highlight/styles/base16/material-palenight.css.hpp"
#include "highlight/styles/base16/material-palenight.min.css.hpp"
#include "highlight/styles/base16/material-vivid.css.hpp"
#include "highlight/styles/base16/material-vivid.min.css.hpp"
#include "highlight/styles/base16/material.css.hpp"
#include "highlight/styles/base16/material.min.css.hpp"
#include "highlight/styles/base16/mellow-purple.css.hpp"
#include "highlight/styles/base16/mellow-purple.min.css.hpp"
#include "highlight/styles/base16/mexico-light.css.hpp"
#include "highlight/styles/base16/mexico-light.min.css.hpp"
#include "highlight/styles/base16/mocha.css.hpp"
#include "highlight/styles/base16/mocha.min.css.hpp"
#include "highlight/styles/base16/monokai.css.hpp"
#include "highlight/styles/base16/monokai.min.css.hpp"
#include "highlight/styles/base16/nebula.css.hpp"
#include "highlight/styles/base16/nebula.min.css.hpp"
#include "highlight/styles/base16/nord.css.hpp"
#include "highlight/styles/base16/nord.min.css.hpp"
#include "highlight/styles/base16/nova.css.hpp"
#include "highlight/styles/base16/nova.min.css.hpp"
#include "highlight/styles/base16/ocean.css.hpp"
#include "highlight/styles/base16/ocean.min.css.hpp"
#include "highlight/styles/base16/oceanicnext.css.hpp"
#include "highlight/styles/base16/oceanicnext.min.css.hpp"
#include "highlight/styles/base16/one-light.css.hpp"
#include "highlight/styles/base16/one-light.min.css.hpp"
#include "highlight/styles/base16/onedark.css.hpp"
#include "highlight/styles/base16/onedark.min.css.hpp"
#include "highlight/styles/base16/outrun-dark.css.hpp"
#include "highlight/styles/base16/outrun-dark.min.css.hpp"
#include "highlight/styles/base16/papercolor-dark.css.hpp"
#include "highlight/styles/base16/papercolor-dark.min.css.hpp"
#include "highlight/styles/base16/papercolor-light.css.hpp"
#include "highlight/styles/base16/papercolor-light.min.css.hpp"
#include "highlight/styles/base16/paraiso.css.hpp"
#include "highlight/styles/base16/paraiso.min.css.hpp"
#include "highlight/styles/base16/pasque.css.hpp"
#include "highlight/styles/base16/pasque.min.css.hpp"
#include "highlight/styles/base16/phd.css.hpp"
#include "highlight/styles/base16/phd.min.css.hpp"
#include "highlight/styles/base16/pico.css.hpp"
#include "highlight/styles/base16/pico.min.css.hpp"
#include "highlight/styles/base16/pop.css.hpp"
#include "highlight/styles/base16/pop.min.css.hpp"
#include "highlight/styles/base16/porple.css.hpp"
#include "highlight/styles/base16/porple.min.css.hpp"
#include "highlight/styles/base16/qualia.css.hpp"
#include "highlight/styles/base16/qualia.min.css.hpp"
#include "highlight/styles/base16/railscasts.css.hpp"
#include "highlight/styles/base16/railscasts.min.css.hpp"
#include "highlight/styles/base16/rebecca.css.hpp"
#include "highlight/styles/base16/rebecca.min.css.hpp"
#include "highlight/styles/base16/ros-pine-dawn.css.hpp"
#include "highlight/styles/base16/ros-pine-dawn.min.css.hpp"
#include "highlight/styles/base16/ros-pine-moon.css.hpp"
#include "highlight/styles/base16/ros-pine-moon.min.css.hpp"
#include "highlight/styles/base16/ros-pine.css.hpp"
#include "highlight/styles/base16/ros-pine.min.css.hpp"
#include "highlight/styles/base16/sagelight.css.hpp"
#include "highlight/styles/base16/sagelight.min.css.hpp"
#include "highlight/styles/base16/sandcastle.css.hpp"
#include "highlight/styles/base16/sandcastle.min.css.hpp"
#include "highlight/styles/base16/seti-ui.css.hpp"
#include "highlight/styles/base16/seti-ui.min.css.hpp"
#include "highlight/styles/base16/shapeshifter.css.hpp"
#include "highlight/styles/base16/shapeshifter.min.css.hpp"
#include "highlight/styles/base16/silk-dark.css.hpp"
#include "highlight/styles/base16/silk-dark.min.css.hpp"
#include "highlight/styles/base16/silk-light.css.hpp"
#include "highlight/styles/base16/silk-light.min.css.hpp"
#include "highlight/styles/base16/snazzy.css.hpp"
#include "highlight/styles/base16/snazzy.min.css.hpp"
#include "highlight/styles/base16/solar-flare-light.css.hpp"
#include "highlight/styles/base16/solar-flare-light.min.css.hpp"
#include "highlight/styles/base16/solar-flare.css.hpp"
#include "highlight/styles/base16/solar-flare.min.css.hpp"
#include "highlight/styles/base16/solarized-dark.css.hpp"
#include "highlight/styles/base16/solarized-dark.min.css.hpp"
#include "highlight/styles/base16/solarized-light.css.hpp"
#include "highlight/styles/base16/solarized-light.min.css.hpp"
#include "highlight/styles/base16/spacemacs.css.hpp"
#include "highlight/styles/base16/spacemacs.min.css.hpp"
#include "highlight/styles/base16/summercamp.css.hpp"
#include "highlight/styles/base16/summercamp.min.css.hpp"
#include "highlight/styles/base16/summerfruit-dark.css.hpp"
#include "highlight/styles/base16/summerfruit-dark.min.css.hpp"
#include "highlight/styles/base16/summerfruit-light.css.hpp"
#include "highlight/styles/base16/summerfruit-light.min.css.hpp"
#include "highlight/styles/base16/synth-midnight-terminal-dark.css.hpp"
#include "highlight/styles/base16/synth-midnight-terminal-dark.min.css.hpp"
#include "highlight/styles/base16/synth-midnight-terminal-light.css.hpp"
#include "highlight/styles/base16/synth-midnight-terminal-light.min.css.hpp"
#include "highlight/styles/base16/tango.css.hpp"
#include "highlight/styles/base16/tango.min.css.hpp"
#include "highlight/styles/base16/tender.css.hpp"
#include "highlight/styles/base16/tender.min.css.hpp"
#include "highlight/styles/base16/tomorrow-night.css.hpp"
#include "highlight/styles/base16/tomorrow-night.min.css.hpp"
#include "highlight/styles/base16/tomorrow.css.hpp"
#include "highlight/styles/base16/tomorrow.min.css.hpp"
#include "highlight/styles/base16/twilight.css.hpp"
#include "highlight/styles/base16/twilight.min.css.hpp"
#include "highlight/styles/base16/unikitty-dark.css.hpp"
#include "highlight/styles/base16/unikitty-dark.min.css.hpp"
#include "highlight/styles/base16/unikitty-light.css.hpp"
#include "highlight/styles/base16/unikitty-light.min.css.hpp"
#include "highlight/styles/base16/vulcan.css.hpp"
#include "highlight/styles/base16/vulcan.min.css.hpp"
#include "highlight/styles/base16/windows-10-light.css.hpp"
#include "highlight/styles/base16/windows-10-light.min.css.hpp"
#include "highlight/styles/base16/windows-10.css.hpp"
#include "highlight/styles/base16/windows-10.min.css.hpp"
#include "highlight/styles/base16/windows-95-light.css.hpp"
#include "highlight/styles/base16/windows-95-light.min.css.hpp"
#include "highlight/styles/base16/windows-95.css.hpp"
#include "highlight/styles/base16/windows-95.min.css.hpp"
#include "highlight/styles/base16/windows-high-contrast-light.css.hpp"
#include "highlight/styles/base16/windows-high-contrast-light.min.css.hpp"
#include "highlight/styles/base16/windows-high-contrast.css.hpp"
#include "highlight/styles/base16/windows-high-contrast.min.css.hpp"
#include "highlight/styles/base16/windows-nt-light.css.hpp"
#include "highlight/styles/base16/windows-nt-light.min.css.hpp"
#include "highlight/styles/base16/windows-nt.css.hpp"
#include "highlight/styles/base16/windows-nt.min.css.hpp"
#include "highlight/styles/base16/woodland.css.hpp"
#include "highlight/styles/base16/woodland.min.css.hpp"
#include "highlight/styles/base16/xcode-dusk.css.hpp"
#include "highlight/styles/base16/xcode-dusk.min.css.hpp"
#include "highlight/styles/base16/zenburn.css.hpp"
#include "highlight/styles/base16/zenburn.min.css.hpp"
#include "highlight/styles/brown-paper.css.hpp"
#include "highlight/styles/brown-paper.min.css.hpp"
#include "highlight/styles/brown-papersq.png.hpp"
#include "highlight/styles/codepen-embed.css.hpp"
#include "highlight/styles/codepen-embed.min.css.hpp"
#include "highlight/styles/color-brewer.css.hpp"
#include "highlight/styles/color-brewer.min.css.hpp"
#include "highlight/styles/dark.css.hpp"
#include "highlight/styles/dark.min.css.hpp"
#include "highlight/styles/default.css.hpp"
#include "highlight/styles/default.min.css.hpp"
#include "highlight/styles/devibeans.css.hpp"
#include "highlight/styles/devibeans.min.css.hpp"
#include "highlight/styles/docco.css.hpp"
#include "highlight/styles/docco.min.css.hpp"
#include "highlight/styles/far.css.hpp"
#include "highlight/styles/far.min.css.hpp"
#include "highlight/styles/felipec.css.hpp"
#include "highlight/styles/felipec.min.css.hpp"
#include "highlight/styles/foundation.css.hpp"
#include "highlight/styles/foundation.min.css.hpp"
#include "highlight/styles/github-dark-dimmed.css.hpp"
#include "highlight/styles/github-dark-dimmed.min.css.hpp"
#include "highlight/styles/github-dark.css.hpp"
#include "highlight/styles/github-dark.min.css.hpp"
#include "highlight/styles/github.css.hpp"
#include "highlight/styles/github.min.css.hpp"
#include "highlight/styles/gml.css.hpp"
#include "highlight/styles/gml.min.css.hpp"
#include "highlight/styles/googlecode.css.hpp"
#include "highlight/styles/googlecode.min.css.hpp"
#include "highlight/styles/gradient-dark.css.hpp"
#include "highlight/styles/gradient-dark.min.css.hpp"
#include "highlight/styles/gradient-light.css.hpp"
#include "highlight/styles/gradient-light.min.css.hpp"
#include "highlight/styles/grayscale.css.hpp"
#include "highlight/styles/grayscale.min.css.hpp"
#include "highlight/styles/hybrid.css.hpp"
#include "highlight/styles/hybrid.min.css.hpp"
#include "highlight/styles/idea.css.hpp"
#include "highlight/styles/idea.min.css.hpp"
#include "highlight/styles/intellij-light.css.hpp"
#include "highlight/styles/intellij-light.min.css.hpp"
#include "highlight/styles/ir-black.css.hpp"
#include "highlight/styles/ir-black.min.css.hpp"
#include "highlight/styles/isbl-editor-dark.css.hpp"
#include "highlight/styles/isbl-editor-dark.min.css.hpp"
#include "highlight/styles/isbl-editor-light.css.hpp"
#include "highlight/styles/isbl-editor-light.min.css.hpp"
#include "highlight/styles/kimbie-dark.css.hpp"
#include "highlight/styles/kimbie-dark.min.css.hpp"
#include "highlight/styles/kimbie-light.css.hpp"
#include "highlight/styles/kimbie-light.min.css.hpp"
#include "highlight/styles/lightfair.css.hpp"
#include "highlight/styles/lightfair.min.css.hpp"
#include "highlight/styles/lioshi.css.hpp"
#include "highlight/styles/lioshi.min.css.hpp"
#include "highlight/styles/magula.css.hpp"
#include "highlight/styles/magula.min.css.hpp"
#include "highlight/styles/mono-blue.css.hpp"
#include "highlight/styles/mono-blue.min.css.hpp"
#include "highlight/styles/monokai-sublime.css.hpp"
#include "highlight/styles/monokai-sublime.min.css.hpp"
#include "highlight/styles/monokai.css.hpp"
#include "highlight/styles/monokai.min.css.hpp"
#include "highlight/styles/night-owl.css.hpp"
#include "highlight/styles/night-owl.min.css.hpp"
#include "highlight/styles/nnfx-dark.css.hpp"
#include "highlight/styles/nnfx-dark.min.css.hpp"
#include "highlight/styles/nnfx-light.css.hpp"
#include "highlight/styles/nnfx-light.min.css.hpp"
#include "highlight/styles/nord.css.hpp"
#include "highlight/styles/nord.min.css.hpp"
#include "highlight/styles/obsidian.css.hpp"
#include "highlight/styles/obsidian.min.css.hpp"
#include "highlight/styles/panda-syntax-dark.css.hpp"
#include "highlight/styles/panda-syntax-dark.min.css.hpp"
#include "highlight/styles/panda-syntax-light.css.hpp"
#include "highlight/styles/panda-syntax-light.min.css.hpp"
#include "highlight/styles/paraiso-dark.css.hpp"
#include "highlight/styles/paraiso-dark.min.css.hpp"
#include "highlight/styles/paraiso-light.css.hpp"
#include "highlight/styles/paraiso-light.min.css.hpp"
#include "highlight/styles/pojoaque.css.hpp"
#include "highlight/styles/pojoaque.jpg.hpp"
#include "highlight/styles/pojoaque.min.css.hpp"
#include "highlight/styles/purebasic.css.hpp"
#include "highlight/styles/purebasic.min.css.hpp"
#include "highlight/styles/qtcreator-dark.css.hpp"
#include "highlight/styles/qtcreator-dark.min.css.hpp"
#include "highlight/styles/qtcreator-light.css.hpp"
#include "highlight/styles/qtcreator-light.min.css.hpp"
#include "highlight/styles/rainbow.css.hpp"
#include "highlight/styles/rainbow.min.css.hpp"
#include "highlight/styles/routeros.css.hpp"
#include "highlight/styles/routeros.min.css.hpp"
#include "highlight/styles/school-book.css.hpp"
#include "highlight/styles/school-book.min.css.hpp"
#include "highlight/styles/shades-of-purple.css.hpp"
#include "highlight/styles/shades-of-purple.min.css.hpp"
#include "highlight/styles/srcery.css.hpp"
#include "highlight/styles/srcery.min.css.hpp"
#include "highlight/styles/stackoverflow-dark.css.hpp"
#include "highlight/styles/stackoverflow-dark.min.css.hpp"
#include "highlight/styles/stackoverflow-light.css.hpp"
#include "highlight/styles/stackoverflow-light.min.css.hpp"
#include "highlight/styles/sunburst.css.hpp"
#include "highlight/styles/sunburst.min.css.hpp"
#include "highlight/styles/tokyo-night-dark.css.hpp"
#include "highlight/styles/tokyo-night-dark.min.css.hpp"
#include "highlight/styles/tokyo-night-light.css.hpp"
#include "highlight/styles/tokyo-night-light.min.css.hpp"
#include "highlight/styles/tomorrow-night-blue.css.hpp"
#include "highlight/styles/tomorrow-night-blue.min.css.hpp"
#include "highlight/styles/tomorrow-night-bright.css.hpp"
#include "highlight/styles/tomorrow-night-bright.min.css.hpp"
#include "highlight/styles/vs.css.hpp"
#include "highlight/styles/vs.min.css.hpp"
#include "highlight/styles/vs2015.css.hpp"
#include "highlight/styles/vs2015.min.css.hpp"
#include "highlight/styles/xcode.css.hpp"
#include "highlight/styles/xcode.min.css.hpp"
#include "highlight/styles/xt256.css.hpp"
#include "highlight/styles/xt256.min.css.hpp"
#include "html/card.html.hpp"
#include "html/einstellungen.html.hpp"
#include "html/index.html.hpp"
#include "ico/toolbox.ico.hpp"
#include "ico/toolbox.png.hpp"

namespace saucer::embedded
{
    inline auto all()
    {
        std::unordered_map<std::string, embedded_file> rtn;

        rtn.emplace("highlight/DIGESTS.md", embedded_file{saucer::stash<>::view(fNgFoiPU0WwvKUr8IMgoyCKoCcxM0ACJwkzkMYv5CO140ln3IgYxq4bE), "text/markdown"});
        rtn.emplace("highlight/es/core.js", embedded_file{saucer::stash<>::view(fNgFoiPU0WwvKUr8IMgoyCKoCcxM0ACJwkzkMYv5CO1qYT7a5MWt9Xmd), "application/javascript"});
        rtn.emplace("highlight/es/core.min.js", embedded_file{saucer::stash<>::view(f1n1OjVncnMWz8SHn4XYmJDagVZXVH28VMzXlj1SVsP9DasdLue0VXnQFn43kp), "application/javascript"});
        rtn.emplace("highlight/es/highlight.js", embedded_file{saucer::stash<>::view(f7OPm7vIuBp2CQunSckZbTM7TWMkL8Kp7Ww7R3u1jcdq48HcUfO9bCLf7GymD35), "application/javascript"});
        rtn.emplace("highlight/es/highlight.min.js", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzsIByLsdRRDqFTtopAfSz2ygwQKNpbQtApHXs28MJB1uSFAcsIuT2gEd), "application/javascript"});
        rtn.emplace("highlight/es/languages/asciidoc.js", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYvwnILiPV0eCBDX5JrQf9CTOck32ID6wfz), "application/javascript"});
        rtn.emplace("highlight/es/languages/asciidoc.min.js", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDCIp7krd2hkMNUMzlc1DJzf4cSgxqUDov6ehaF), "application/javascript"});
        rtn.emplace("highlight/es/languages/http.js", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1rUB7RCLarIP9jvSTrI3Dg4IbJEiAP4Z1ohkwmKDPV13ePEn779QnSFH07), "application/javascript"});
        rtn.emplace("highlight/es/languages/http.min.js", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYvwnILiPV0eCBDX5JrQfpX1rAatgTLHqQl), "application/javascript"});
        rtn.emplace("highlight/es/languages/json.js", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1rUB7RCLarIP9jvSTrI3Dg4IbJEiAP4Z1ohkwmKDPV13ePEn79iy6t5rL1), "application/javascript"});
        rtn.emplace("highlight/es/languages/json.min.js", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYvwnILiPV0eCBDX5JrQg1axoC83pRnnmcN), "application/javascript"});
        rtn.emplace("highlight/es/languages/lua.js", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzsIByLsdRRDqFTtopAfSz2ygwQKNpbQtApHfMMKgVFGrra2CsoEivKh1), "application/javascript"});
        rtn.emplace("highlight/es/languages/lua.min.js", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLXh6K57B7Mm0XzMAcFFlpl71uOs77OvcwRD0aCpz4t1p7aIGdHr5zSiakl7w2N), "application/javascript"});
        rtn.emplace("highlight/es/languages/markdown.js", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYvwnILiPV0eCBDX5JrQgJIm4JydXIzpx3L), "application/javascript"});
        rtn.emplace("highlight/es/languages/markdown.min.js", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDCIp7krd2hkMNUMzlc6fLQq0oOnkTQVHmOpZLf), "application/javascript"});
        rtn.emplace("highlight/es/languages/shell.js", embedded_file{saucer::stash<>::view(f9WyAbPBHunlngqbuiIzAC3zsDdFbI2XIThko3QkMxWqdVMfqhXTNI4N4qD4oJpfZ7rulBT), "application/javascript"});
        rtn.emplace("highlight/es/languages/shell.min.js", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFGlXlfNI2fyIJsby0cD86kRNNGXzrk6JQB), "application/javascript"});
        rtn.emplace("highlight/es/languages/sql.js", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzsIByLsdRRDqFTtopAfSz2ygwQKNpbQtApHfMMKgVFGrra2CuzRKrsLD), "application/javascript"});
        rtn.emplace("highlight/es/languages/sql.min.js", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLXh6K57B7Mm0XzMAcFFlpl71uOs77OvcwRD0aCpz4t1p7aIGdS4wvQ02KO4mx9), "application/javascript"});
        rtn.emplace("highlight/es/languages/xml.js", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzsIByLsdRRDqFTtopAfSz2ygwQKNpbQtApHfMMKgVFGrra2CwXvPiadX), "application/javascript"});
        rtn.emplace("highlight/es/languages/xml.min.js", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLXh6K57B7Mm0XzMAcFFlpl71uOs77OvcwRD0aCpz4t1p7aIGdZNHndpIxHi20R), "application/javascript"});
        rtn.emplace("highlight/es/package.json", embedded_file{saucer::stash<>::view(f7OPm7vIuBp2CQunSckZbTM7TWMkL8Kp7Ww7R3u1jcdq48HfhWZvP04VK21lq7K), "application/json"});
        rtn.emplace("highlight/highlight.js", embedded_file{saucer::stash<>::view(f6Vk928ltQ1ldIIiq9NQmLwFAYuZA1VsOTN6DQA4JUM5SwmaSqwyXxFO2kt), "application/javascript"});
        rtn.emplace("highlight/highlight.min.js", embedded_file{saucer::stash<>::view(fUWoQiic40oj5L8WEC0J0jDKrtdvLGPz55zyhk7LANYaZUecs4m2xF3tT66D9ajr), "application/javascript"});
        rtn.emplace("highlight/languages/asciidoc.js", embedded_file{saucer::stash<>::view(f9WyAbPBHunlngqbuiIzAC3zsDdFbI2XIThko3QkMxWuidWEKkrjwnkFUMMIrtILqxuyS5D), "application/javascript"});
        rtn.emplace("highlight/languages/asciidoc.min.js", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFZuGInDtCEjq6oPrZRIEbXNohLc3o3Xzv9), "application/javascript"});
        rtn.emplace("highlight/languages/http.js", embedded_file{saucer::stash<>::view(f223UEKeDAZNSA3HB4bZGV0h4AXkqlnnID2luecQJOrHJvlydt7E9VELJd4XHqmZvv), "application/javascript"});
        rtn.emplace("highlight/languages/http.min.js", embedded_file{saucer::stash<>::view(f9WyAbPBHunlngqbuiIzAC3zsDdFbI2XIThko3QkMxWuidWEKkrjwnkFV2grKR9CV939Lpz), "application/javascript"});
        rtn.emplace("highlight/languages/json.js", embedded_file{saucer::stash<>::view(f223UEKeDAZNSA3HB4bZGV0h4AXkqlnnID2luecQJOrHJvlydt7E9VELJfe4bHdAGp), "application/javascript"});
        rtn.emplace("highlight/languages/json.min.js", embedded_file{saucer::stash<>::view(f9WyAbPBHunlngqbuiIzAC3zsDdFbI2XIThko3QkMxWuidWEKkrjwnkFVEknHSgMe7VfI1b), "application/javascript"});
        rtn.emplace("highlight/languages/lua.js", embedded_file{saucer::stash<>::view(fUWoQiic40oj5L8WEC0J0jDKrtdvLGPz55zyhk7LANYi3oqx4910MZvTTbQT2FCF), "application/javascript"});
        rtn.emplace("highlight/languages/lua.min.js", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1rUB7RCLarIP9jvSTrI3Dg4IbJEiAP4a17dI0BLjWA6qByHD80H3WsK0lH), "application/javascript"});
        rtn.emplace("highlight/languages/markdown.js", embedded_file{saucer::stash<>::view(f9WyAbPBHunlngqbuiIzAC3zsDdFbI2XIThko3QkMxWuidWEKkrjwnkFVWSbXaWwLyhhSSZ), "application/javascript"});
        rtn.emplace("highlight/languages/markdown.min.js", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFZuGInDtCEjq6oVJasTAnTUbKHtWfLirgZ), "application/javascript"});
        rtn.emplace("highlight/languages/shell.js", embedded_file{saucer::stash<>::view(f8OUOpBG2Ne4qHVWvj17c82rpDXNRtNbXBrRpviee6dzWIY6OhZqRExE1zdSMdBQvrv), "application/javascript"});
        rtn.emplace("highlight/languages/shell.min.js", embedded_file{saucer::stash<>::view(fdM8RmRybyXVNAvEYAwOY5oVTsI4PyUTUIefGgARSnnuCJB5BhVtinOy4aRKyDiuFE4r1zZz), "application/javascript"});
        rtn.emplace("highlight/languages/sql.js", embedded_file{saucer::stash<>::view(fUWoQiic40oj5L8WEC0J0jDKrtdvLGPz55zyhk7LANYi3oqx4910MZvTVmd4ymqR), "application/javascript"});
        rtn.emplace("highlight/languages/sql.min.js", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1rUB7RCLarIP9jvSTrI3Dg4IbJEiAP4a17dI0BLjWA6qC8V43xYV6VGrg3), "application/javascript"});
        rtn.emplace("highlight/languages/xml.js", embedded_file{saucer::stash<>::view(fUWoQiic40oj5L8WEC0J0jDKrtdvLGPz55zyhk7LANYi3oqx4910MZvTXL79pV8l), "application/javascript"});
        rtn.emplace("highlight/languages/xml.min.js", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1rUB7RCLarIP9jvSTrI3Dg4IbJEiAP4a17dI0BLjWA6qCFnOwBNljOu6jL), "application/javascript"});
        rtn.emplace("highlight/package.json", embedded_file{saucer::stash<>::view(f6Vk928ltQ1ldIIiq9NQmLwFAYuZA1VsOTN6DQA4JUM8fnyMGefokiINfp8), "application/json"});
        rtn.emplace("highlight/README.md", embedded_file{saucer::stash<>::view(f5jaldojX46WI2d1WXaWgfjj5xoDYuidhmC2zeQPxff1ZK8s0M4H7Dg), "text/markdown"});
        rtn.emplace("highlight/styles/1c-light.css", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzsIByLsdRRDqFTtopAfSz2ygwQKNpbRNB5LbB936yxY4jBs2TZ3RXmTb), "text/css"});
        rtn.emplace("highlight/styles/1c-light.min.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLXh6K57B7Mm0XzMAcFFlpl71uOs77OvfD6NfV7hDpSyj4JCzfFDLPgapWoFREx), "text/css"});
        rtn.emplace("highlight/styles/a11y-dark.css", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1rUB7RCLarIP9jvSTrI3Dg4IbJEiAP4b1hm5BW1Ms79fFqFU0WfsTpZoXr), "text/css"});
        rtn.emplace("highlight/styles/a11y-dark.min.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTCW7Y2bBPyBoQT3Zw1euOGbz), "text/css"});
        rtn.emplace("highlight/styles/a11y-light.css", embedded_file{saucer::stash<>::view(f9WyAbPBHunlngqbuiIzAC3zsDdFbI2XIThko3QkMxWyt2kXPYDeRRXuLPjykgjBiYwtF4N), "text/css"});
        rtn.emplace("highlight/styles/a11y-light.min.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFtRiDjIxE8ZgdAYjXMa2zdzPHk13jjo0u3), "text/css"});
        rtn.emplace("highlight/styles/agate.css", embedded_file{saucer::stash<>::view(fUWoQiic40oj5L8WEC0J0jDKrtdvLGPz55zyhk7LANYvPT5eDQFdAsJxPS9bOyAd), "text/css"});
        rtn.emplace("highlight/styles/agate.min.css", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1rUB7RCLarIP9jvSTrI3Dg4IbJEiAP4b1hm5BW1Ms7VTUrOGU4mpiNg0P5), "text/css"});
        rtn.emplace("highlight/styles/an-old-hope.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVNAvEYAwOY5oVTsI4PyUTUIefGgARSnoBPHM9xVIMzQUUd1BQTVmNaSjOIgUt), "text/css"});
        rtn.emplace("highlight/styles/an-old-hope.min.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUToQOm3w59e9grF6T0ZEBr1zEYCiKNSePcwQah4GYNPrfeDEMZD3rJQucpQCo2HKeo7), "text/css"});
        rtn.emplace("highlight/styles/androidstudio.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTCXz1rs4quK1hjkfafaqlqjr), "text/css"});
        rtn.emplace("highlight/styles/androidstudio.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8McKkkdN1nJY9Orql2zqoFt3pmUjNz), "text/css"});
        rtn.emplace("highlight/styles/arduino-light.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTCY6ZqIWV28unhhBxmp6MmG3), "text/css"});
        rtn.emplace("highlight/styles/arduino-light.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8McLK8ZKNHZN7CcrWNfyswGWKGjZml), "text/css"});
        rtn.emplace("highlight/styles/arta.css", embedded_file{saucer::stash<>::view(f7OPm7vIuBp2CQunSckZbTM7TWMkL8Kp7Ww7R3u1jcdwSvu6LekPTHGCbynnMSB), "text/css"});
        rtn.emplace("highlight/styles/arta.min.css", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzsIByLsdRRDqFTtopAfSz2ygwQKNpbRNB5LbB937IIsDC8p0X5SPgC7H), "text/css"});
        rtn.emplace("highlight/styles/ascetic.css", embedded_file{saucer::stash<>::view(f8OUOpBG2Ne4qHVWvj17c82rpDXNRtNbXBrRpviee6e3Bt3mEo8zLNy1hrmkv9DPYup), "text/css"});
        rtn.emplace("highlight/styles/ascetic.min.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVNAvEYAwOY5oVTsI4PyUTUIefGgARSnoBPHM9xVIMzR4FZrARKNA5b5YVwDhr), "text/css"});
        rtn.emplace("highlight/styles/atom-one-dark-reasonable.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8YqqCcyksubNH8qdyXguYFtlmZZY9iwSYne1wT8tKJpN4dgYhv2DGP1vgLh00XH03ikMEmC8JNrN6x), "text/css"});
        rtn.emplace("highlight/styles/atom-one-dark-reasonable.min.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89ozqBfmWiugWw7F9lB3mLRBNVZtPMh5QD8Ln9JOyACAbCXVDTf1A2uFGAbQ0dqiQg2DRDwRUrO6Lbt9fk2N), "text/css"});
        rtn.emplace("highlight/styles/atom-one-dark.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTCYAQq6ryYWZgxVV4Od4KAdP), "text/css"});
        rtn.emplace("highlight/styles/atom-one-dark.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8McLcD1RJUQHk30v6B1Z95YQssTzYB), "text/css"});
        rtn.emplace("highlight/styles/atom-one-light.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFtRiDjIxE8Zp54pAMs2YVNQYa6QShqIRyl), "text/css"});
        rtn.emplace("highlight/styles/atom-one-light.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XOLFllwmTcXG8f9HixAY2IbDPrRZBb), "text/css"});
        rtn.emplace("highlight/styles/base16/3024.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVNAvEYAwOY5oVTsI4PyUTUIefGgARSnoBPHM9xVIMzrPsCFWA8NTbmGqvZmBH), "text/css"});
        rtn.emplace("highlight/styles/base16/3024.min.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUToQOm3w59e9grF6T0ZEBr1zEYCiKNSePcwQah4GYNRttwzjFpIT25F18cNRR7Of2Bf), "text/css"});
        rtn.emplace("highlight/styles/base16/apathy.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTCfNfpoaxpqGDqNUE9ktb4ZX), "text/css"});
        rtn.emplace("highlight/styles/base16/apathy.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWI8cx1XMJvEbKADHqkmqh), "text/css"});
        rtn.emplace("highlight/styles/base16/apprentice.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWI8cx7ZUE0ppwHfoflWcd), "text/css"});
        rtn.emplace("highlight/styles/base16/apprentice.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg5RsgDTn9lcH9GPl4F9U58nYIzkvl7m1aexCmBAz0Avr1ikw26S5jymOdOqY5ZrmaNFmPsZeD5), "text/css"});
        rtn.emplace("highlight/styles/base16/ashes.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLXh6K57B7Mm0XzMAcFFlpl71uOs77OvfD6NfV7hDqxQYpma4nqrL37rkyi3bNb), "text/css"});
        rtn.emplace("highlight/styles/base16/ashes.min.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr6D0ISFpHpo0xqMhmLSawyCq5EV28sIronFnVpcLwpCp1asrLpUlTtgv9li4oiNhYqx), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-cave-light.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVLuBY8wrajiK6mXN3z7BVReHIYsn29ZNvgzI1QKiS5rOuFDY4LaTTa9TGk4k7chFFx69nVszq9DbDHP), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-cave-light.min.css", embedded_file{saucer::stash<>::view(f1MJy0Jkn1m1RgYZLUCWN7S3bzxuaInfbcWEz4OCmjhuOEETywS76R0SOXQ7JUihPG9FQXrpz9J5wm9XUH2GbYUH3DJirlu8B), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-cave.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUU1oKBNuCv8HiBJD6wcFE206yebte5qt), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-cave.min.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MyGW7VBM1775bV9gGsTCAdB5SxT6EH40g3Ogjo6cLyOgu45ctk5HGgzSqO6skVetdu9Z7ST7wYE7), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-dune-light.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVLuBY8wrajiK6mXN3z7BVReHIYsn29ZNvgzI1QKiS5rOuFDY4LaTTa9TGk4k7k5syGH54IFvNJXqxDH), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-dune-light.min.css", embedded_file{saucer::stash<>::view(f1MJy0Jkn1m1RgYZLUCWN7S3bzxuaInfbcWEz4OCmjhuOEETywS76R0SOXQ7JUihPG9FQXrpz9rm7e4OG9bogTezFrcBBO8Jf), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-dune.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUU1oKBNuCv8HiBJD6wcFE25qkEb8NIAN), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-dune.min.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MyGW7VBM1775bV9gGsTCAdB5SxT6EH40g3Ogjo6cLyOgu45ctk5HGgzSqO6skwYmrt7p7gU0nNI3), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-estuary-light.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89ozqBfmWiugWw7F9lB3mLRBNVZtPMh5QD8Ln9JOyAPmX4Dae518ZfCtZ0S3O13nixDJXkfhNeAJMz0pdyHj), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-estuary-light.min.css", embedded_file{saucer::stash<>::view(f1XjtLeY7kEHn3uAOla2WtIqkhmArnwhH4LSzKePpbJipdsv3YnYnbu7pu0PwwkJCJwvqsrZri7lDpXBSNkiZb5bW6rDmS9nzLq1T), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-estuary.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYTmV7mJf0yKc2oFmMLWZADEKbeQzmUa6IZN6Skw9Lsj8sx6nncge1l9RTkaq2bcaL45HdmnkSlQB), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-estuary.min.css", embedded_file{saucer::stash<>::view(f1CGTDaSS4GQFtSRzgyx3Hgl120PnESLfVqAJQe2EStW6oDV4PsjXY0CUqEpwfx8bi9H6r8FaSQRSLj2QC8M5A0GvhPzH), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-forest-light.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPczTajTfpZ2Y8GHiVHh3TPTOaE1JDjJEa7LkIEs02WOpbLhGUHEBXiIIeJO4MZELKYpZPLrqKMGQMpcXwZ), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-forest-light.min.css", embedded_file{saucer::stash<>::view(fNBb8dMnLMpmD3QjiSaSJCnaUwePcjhPviuuVdoolIp3mtRNcwVC0wdg7GZLXbN3T38CK4Fx1cgFR1jHVXqcqj64tpky1TZQcip), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-forest.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg5RsgDTn9lcH9GPl4F9U58nYIzkvl7m1aexCmBAz0Avr1ikw26S6EoEt9pXuon3C0KJAInq1HX), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-forest.min.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVLuBY8wrajiK6mXN3z7BVReHIYsn29ZNvgzI1QKiS5rOuFDY4LaTTa9TGk4k7xeqd0tgcMGtubfj5gh), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-heath-light.css", embedded_file{saucer::stash<>::view(f1CGTDaSS4GQFtSRzgyx3Hgl120PnESLfVqAJQe2EStW6oDV4PsjXY0CUqEpwfx8bi9H6r8FaTlt10rk2JRQ2YWqocb5v), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-heath-light.min.css", embedded_file{saucer::stash<>::view(f5cARlJZCRKHyJijwihhfSlqutrNdtd5nL37sA7wnEjIq2lnndM5KZVtFJzqCUqZEIgBhbqIefB3GpDvpV433j3vIiDm4MqxaF), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-heath.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV1JpVXIM4mpPSsplj6Zia7ST8TUFvQaKjCp9OGGhprzTnL0i5LuD8QhK8g1ury2h4xwgb5imx), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-heath.min.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8YqqCcyksubNH8qdyXguYFtlmZZY9iwSYne1wT8tKMjNx9UtEcAHnIvVn6JYQCNUvTUrIzfRCnxGkN), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-lakeside-light.css", embedded_file{saucer::stash<>::view(f1MJy0Jkn1m1RgYZLUCWN7S3bzxuaInfbcWEz4OCmjhuOEETywS76R0SOXQ7JUihPG9FQXrpzDycvzdQ1Uhtholt4YAOiKsfD), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-lakeside-light.min.css", embedded_file{saucer::stash<>::view(f6NJUXPQtyszSa7uwGSoRoLpoqkusAEMgTwdhFGsf45R7EglahgdgqVkMJFj9OZDGsNKsMXE633AnKhcRPWZzSPmcwh5BM1pRJYHLP), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-lakeside.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MyGW7VBM1775bV9gGsTCAdB5SxT6EH40g3Ogjo6cLyOgu45ctk5HGgzSqO6so8FTWcWnk0bWeRG7), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-lakeside.min.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPczTajTfpZ2Y8GHiVHh3TPTOaE1JDjJEa7LkIEs02WOpbLhGUHEBXiIIeJO4MkRt1ZgSVtb7o0kbE3TCZ1), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-plateau-light.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89ozqBfmWiugWw7F9lB3mLRBNVZtPMh5QD8Ln9JOyAPmX4Dae518ZfCtZ0S3O2RI5iRNaxsH9Kon0OwR6QNv), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-plateau-light.min.css", embedded_file{saucer::stash<>::view(f1XjtLeY7kEHn3uAOla2WtIqkhmArnwhH4LSzKePpbJipdsv3YnYnbu7pu0PwwkJCJwvqsrZroaY8KT6V6NkH74PlCxgtoICw3kkF), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-plateau.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYTmV7mJf0yKc2oFmMLWZADEKbeQzmUa6IZN6Skw9Lsj8sx6nncge1l9RTkaq2cgtphYwsYk1RDwx), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-plateau.min.css", embedded_file{saucer::stash<>::view(f1CGTDaSS4GQFtSRzgyx3Hgl120PnESLfVqAJQe2EStW6oDV4PsjXY0CUqEpwfx8bi9H6r8FaXRKknGMfMP68Vu6onDON), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-savanna-light.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89ozqBfmWiugWw7F9lB3mLRBNVZtPMh5QD8Ln9JOyAPmX4Dae518ZfCtZ0S3O2oKgTERvHGUojdyQ1hIgv7j), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-savanna-light.min.css", embedded_file{saucer::stash<>::view(f1XjtLeY7kEHn3uAOla2WtIqkhmArnwhH4LSzKePpbJipdsv3YnYnbu7pu0PwwkJCJwvqsrZrqKZabkRnH4m7ioStTSEcRk13VhNT), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-savanna.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYTmV7mJf0yKc2oFmMLWZADEKbeQzmUa6IZN6Skw9Lsj8sx6nncge1l9RTkaq2cylzZp6M2obnmmB), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-savanna.min.css", embedded_file{saucer::stash<>::view(f1CGTDaSS4GQFtSRzgyx3Hgl120PnESLfVqAJQe2EStW6oDV4PsjXY0CUqEpwfx8bi9H6r8FaYn7yBApCaURqvLXJdlPH), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-seaside-light.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89ozqBfmWiugWw7F9lB3mLRBNVZtPMh5QD8Ln9JOyAPmX4Dae518ZfCtZ0S3O2oS4sIsjadnItY9cZV321Uh), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-seaside-light.min.css", embedded_file{saucer::stash<>::view(f1XjtLeY7kEHn3uAOla2WtIqkhmArnwhH4LSzKePpbJipdsv3YnYnbu7pu0PwwkJCJwvqsrZrqL8Ffy6OpwD9eKAs156bBVwVL4TL), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-seaside.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYTmV7mJf0yKc2oFmMLWZADEKbeQzmUa6IZN6Skw9Lsj8sx6nncge1l9RTkaq2cyrjA2qiM2B20u3), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-seaside.min.css", embedded_file{saucer::stash<>::view(f1CGTDaSS4GQFtSRzgyx3Hgl120PnESLfVqAJQe2EStW6oDV4PsjXY0CUqEpwfx8bi9H6r8FaYnYrD9E5sLsZDDpXuGMl), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-sulphurpool-light.css", embedded_file{saucer::stash<>::view(f1XjtLeY7kEHn3uAOla2WtIqkhmArnwhH4LSzKePpbJipdsv3YnYnbu7pu0PwwkJCJwvqsrZrqNQArErp8a0yyAHFAQFH6izetfRT), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-sulphurpool-light.min.css", embedded_file{saucer::stash<>::view(f7EqLhcRLMrUY9lXNEZfe35W7jd0izyoQnfZwBbXIB51QWmhjj8HL1MWn4UglAjlihrX1XHgRZBcKNRxGOHsrVV7sPpKNTDh5ZKXYNUdYR), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-sulphurpool.css", embedded_file{saucer::stash<>::view(f1CGTDaSS4GQFtSRzgyx3Hgl120PnESLfVqAJQe2EStW6oDV4PsjXY0CUqEpwfx8bi9H6r8FaYpKwjeRKgwxWZ7xraDD9), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-sulphurpool.min.css", embedded_file{saucer::stash<>::view(f5cARlJZCRKHyJijwihhfSlqutrNdtd5nL37sA7wnEjIq2lnndM5KZVtFJzqCUqZEIgBhbqIf2sYR6cvMGy5ZbQgvFwxWa5Cl9), "text/css"});
        rtn.emplace("highlight/styles/base16/atlas.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLXh6K57B7Mm0XzMAcFFlpl71uOs77OvfD6NfV7hDqxQYpma4nqrL8X1k0011d5), "text/css"});
        rtn.emplace("highlight/styles/base16/atlas.min.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr6D0ISFpHpo0xqMhmLSawyCq5EV28sIronFnVpcLwpCp1asrLpUltEyaJmsfQQxCVet), "text/css"});
        rtn.emplace("highlight/styles/base16/bespin.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTCfNfpoaxpqHciiIzSr7pKUd), "text/css"});
        rtn.emplace("highlight/styles/base16/bespin.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWI8jWJTxZvfz3VzUCXJh5), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-bathory.css", embedded_file{saucer::stash<>::view(f1CGTDaSS4GQFtSRzgyx3Hgl120PnESLfVqAJQe2EStW6oDV4PsjXY0CUqEpwfxIKxXOqH9p8evV0GyyuS9iUaZl5QkHz), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-bathory.min.css", embedded_file{saucer::stash<>::view(f5cARlJZCRKHyJijwihhfSlqutrNdtd5nL37sA7wnEjIq2lnndM5KZVtFJzqCUrIqPy2vu8uZOXdvAtFOOfSCwm5XSD5b4Qr8V), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-burzum.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVLuBY8wrajiK6mXN3z7BVReHIYsn29ZNvgzI1QKiS5rOuFDY4LcpZjNwBu8zfsc1WCpg4TethrAiR0d), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-burzum.min.css", embedded_file{saucer::stash<>::view(f1MJy0Jkn1m1RgYZLUCWN7S3bzxuaInfbcWEz4OCmjhuOEETywS76R0SOXQ7JUisSC6J7F37t4UQcY7ZkOphTMu1WiaMn5vl5), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-dark-funeral.css", embedded_file{saucer::stash<>::view(fNBb8dMnLMpmD3QjiSaSJCnaUwePcjhPviuuVdoolIp3mtRNcwVC0wdg7GZLXbQ5oRDw75ona9Kuq51tXZDQg81e6KzzVd3gYB1), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-dark-funeral.min.css", embedded_file{saucer::stash<>::view(f1khg4GZgTGpTaGq9zAZkzmJt9b3Z7GBFCztgfYlIRs0pTFfakHzM2kcwNqxlGeNNOUZClVQK2kmd9ON90X36GvjETpxFb5qpqdxpkD4d), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-gorgoroth.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89ozqBfmWiugWw7F9lB3mLRBNVZtPMh5QD8Ln9JOyAPmX4Dae51BFXviLc2D3AI1bQfgbDs3kzf1Oe5wwuQN), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-gorgoroth.min.css", embedded_file{saucer::stash<>::view(f1XjtLeY7kEHn3uAOla2WtIqkhmArnwhH4LSzKePpbJipdsv3YnYnbu7pu0PwwkVk0GPXxI1kjGYMh39cwaydSlEv66ERA210MwK3), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-immortal.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPczTajTfpZ2Y8GHiVHh3TPTOaE1JDjJEa7LkIEs02WOpbLhGUHEpiXpuZqqZ9kzQ18AdLtGgUEKZeo3U4x), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-immortal.min.css", embedded_file{saucer::stash<>::view(fNBb8dMnLMpmD3QjiSaSJCnaUwePcjhPviuuVdoolIp3mtRNcwVC0wdg7GZLXbQ5oRDw75ona9Kuq5BPye6Bue6KS9rLSWYJnuN), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-khold.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8YqqCcyksubNH8qdyXguYFtlmZZY9iwSYne1wT8tKMjNx9UtEcArB4h5rG1CzyD5D80Bg1PkfEUueJ), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-khold.min.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89ozqBfmWiugWw7F9lB3mLRBNVZtPMh5QD8Ln9JOyAPmX4Dae51BFXviLc2D3AI1bQfnCYimpWweh4FHKgRn), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-marduk.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVLuBY8wrajiK6mXN3z7BVReHIYsn29ZNvgzI1QKiS5rOuFDY4LcpZjNwBu8zfsc1WD5fF23NZk0tkjD), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-marduk.min.css", embedded_file{saucer::stash<>::view(f1MJy0Jkn1m1RgYZLUCWN7S3bzxuaInfbcWEz4OCmjhuOEETywS76R0SOXQ7JUisSC6J7F37t4UQcY8mh9ZT9ZxMGn1IzEXbP), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-mayhem.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVLuBY8wrajiK6mXN3z7BVReHIYsn29ZNvgzI1QKiS5rOuFDY4LcpZjNwBu8zfsc1WD5fFdOcwjUayep), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-mayhem.min.css", embedded_file{saucer::stash<>::view(f1MJy0Jkn1m1RgYZLUCWN7S3bzxuaInfbcWEz4OCmjhuOEETywS76R0SOXQ7JUisSC6J7F37t4UQcY8mhCOXNg4MjvKATmmfr), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-nile.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MyGW7VBM1775bV9gGsTCAdB5SxT6EH40g3Ogjo6cLyOgu45ctkDqZWiWkzK6HyK9TYD0Jx5YEiIN), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-nile.min.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPczTajTfpZ2Y8GHiVHh3TPTOaE1JDjJEa7LkIEs02WOpbLhGUHEpiXpuZqqZ9kzQ18CdjiDNmCNF4dEbo3), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-venom.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8YqqCcyksubNH8qdyXguYFtlmZZY9iwSYne1wT8tKMjNx9UtEcArB4h5rG1CzyD5D845BXBb24pBo3), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-venom.min.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89ozqBfmWiugWw7F9lB3mLRBNVZtPMh5QD8Ln9JOyAPmX4Dae51BFXviLc2D3AI1bQg5SmmQFUBUtBfKjnyl), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XQatGJpsTKu4iyclIfeyUijXwJgSRP), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal.min.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYTmV7mJf0yKc2oFmMLWZADEKbeQzmUa6IZN6Skw9Lsj8sx6nncgg6R0eoYd4NnsoPXsl4V8YSomB), "text/css"});
        rtn.emplace("highlight/styles/base16/brewer.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTCfNfpoaxpqHhJEnKxi3dTmd), "text/css"});
        rtn.emplace("highlight/styles/base16/brewer.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWI8jrpNCjmC92TpYmvOr5), "text/css"});
        rtn.emplace("highlight/styles/base16/bright.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTCfNfpoaxpqHhJZkp8wWaF0N), "text/css"});
        rtn.emplace("highlight/styles/base16/bright.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWI8jrqxSvQAPP65ohbEe3), "text/css"});
        rtn.emplace("highlight/styles/base16/brogrammer.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWI8jrtNCNwHWiF1UC5vzn), "text/css"});
        rtn.emplace("highlight/styles/base16/brogrammer.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg5RsgDTn9lcH9GPl4F9U58nYIzkvl7m1aexCmBAz0Avr1ikw26ScA7bc3yVD8db3WsADP91Bdj), "text/css"});
        rtn.emplace("highlight/styles/base16/brush-trees-dark.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MyGW7VBM1775bV9gGsTCAdB5SxT6EH40g3Ogjo6cLyOgu45ctkE3awXEebwUVkvHLI7gccdy4md1), "text/css"});
        rtn.emplace("highlight/styles/base16/brush-trees-dark.min.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPczTajTfpZ2Y8GHiVHh3TPTOaE1JDjJEa7LkIEs02WOpbLhGUHEqhb7ni4P5UNpdJT3A94aGbDaXKAsYsd), "text/css"});
        rtn.emplace("highlight/styles/base16/brush-trees.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XQatGJpsTKu5OggqLOKrQycJHGAj5v), "text/css"});
        rtn.emplace("highlight/styles/base16/brush-trees.min.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYTmV7mJf0yKc2oFmMLWZADEKbeQzmUa6IZN6Skw9Lsj8sx6nncgg9aYWGctgk8euUqEG5fegbTaF), "text/css"});
        rtn.emplace("highlight/styles/base16/chalk.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLXh6K57B7Mm0XzMAcFFlpl71uOs77OvfD6NfV7hDqxQYpma4nqs23nArMzAWax), "text/css"});
        rtn.emplace("highlight/styles/base16/chalk.min.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr6D0ISFpHpo0xqMhmLSawyCq5EV28sIronFnVpcLwpCp1asrLpY17ct7aCi7GZP09yN), "text/css"});
        rtn.emplace("highlight/styles/base16/circus.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTCfNfpoaxpqJ6t61zfxcN79X), "text/css"});
        rtn.emplace("highlight/styles/base16/circus.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWI8qUPMODNGJKrQUT3vAh), "text/css"});
        rtn.emplace("highlight/styles/base16/classic-dark.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUU1oKBNuCv8LQVFG0ERxGHX9GGmNFUfL), "text/css"});
        rtn.emplace("highlight/styles/base16/classic-dark.min.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MyGW7VBM1775bV9gGsTCAdB5SxT6EH40g3Ogjo6cLyOgu45ctkMh3A817aSFvSrSh2EkguJbsgtv), "text/css"});
        rtn.emplace("highlight/styles/base16/classic-light.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV1JpVXIM4mpPSsplj6Zia7ST8TUFvQaKjCp9OGGhprzTnL0i5LuSTR104xfQhHFO3S37yz9yF), "text/css"});
        rtn.emplace("highlight/styles/base16/classic-light.min.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8YqqCcyksubNH8qdyXguYFtlmZZY9iwSYne1wT8tKMjNx9UtEcBRhl3p6dKWfycgxuOfQ9ajnJQYxX), "text/css"});
        rtn.emplace("highlight/styles/base16/codeschool.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWI8qeHxx9OegIU2lhuTcx), "text/css"});
        rtn.emplace("highlight/styles/base16/codeschool.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg5RsgDTn9lcH9GPl4F9U58nYIzkvl7m1aexCmBAz0Avr1ikw26T7x0IorecBLeS6Yp47KmsM6N), "text/css"});
        rtn.emplace("highlight/styles/base16/colors.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTCfNfpoaxpqJ90SR0EBMuSwt), "text/css"});
        rtn.emplace("highlight/styles/base16/colors.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWI8qeLCZCTYg6cYijvCc7), "text/css"});
        rtn.emplace("highlight/styles/base16/cupcake.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFtRiDjIxE8aIrkjwud43zBzndXNjOX4St1), "text/css"});
        rtn.emplace("highlight/styles/base16/cupcake.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XQatGJpsTKuY3qq2z2ExWqqtoAuNud), "text/css"});
        rtn.emplace("highlight/styles/base16/cupertino.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr6D0ISFpHpo0xqMhmLSawyCq5EV28sIronFnVpcLwpCp1asrLpY6NV2GCvROR1npFXX), "text/css"});
        rtn.emplace("highlight/styles/base16/cupertino.min.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV1JpVXIM4mpPSsplj6Zia7ST8TUFvQaKjCp9OGGhprzTnL0i5LuSkWmBDmFaWrAEUksaYJ6ih), "text/css"});
        rtn.emplace("highlight/styles/base16/danqing.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFtRiDjIxE8aIrkjwud444lQKY9Fm43lpat), "text/css"});
        rtn.emplace("highlight/styles/base16/danqing.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XQatGJpsTKuyBGjCAzqQaoMuWlQPC7), "text/css"});
        rtn.emplace("highlight/styles/base16/darcula.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFtRiDjIxE8aIrkjwud444lRjGbVILEuJVb), "text/css"});
        rtn.emplace("highlight/styles/base16/darcula.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XQatGJpsTKuyBNHjnmkhNtoXsfZxMx), "text/css"});
        rtn.emplace("highlight/styles/base16/dark-violet.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XQatGJpsTKuyBNKqQVNag4NmqMZpgp), "text/css"});
        rtn.emplace("highlight/styles/base16/dark-violet.min.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYTmV7mJf0yKc2oFmMLWZADEKbeQzmUa6IZN6Skw9Lsj8sx6nncgkIQjc0jwX0GWmxlY92NCtSanr), "text/css"});
        rtn.emplace("highlight/styles/base16/darkmoss.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUToQOm3w59e9grF6T0ZEBr1zEYCiKNSePcwQah4GYNRttwzjFpImpfuXjhnFhF3gbyN), "text/css"});
        rtn.emplace("highlight/styles/base16/darkmoss.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUU1oKBNuCv8NEUyMUDsZbzC5cXnIyKW3), "text/css"});
        rtn.emplace("highlight/styles/base16/darktooth.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr6D0ISFpHpo0xqMhmLSawyCq5EV28sIronFnVpcLwpCp1asrLpZdN3TLCg3eHvsFgaB), "text/css"});
        rtn.emplace("highlight/styles/base16/darktooth.min.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV1JpVXIM4mpPSsplj6Zia7ST8TUFvQaKjCp9OGGhprzTnL0i5LuZvrtF2Qa8wrMjcABiLL2dH), "text/css"});
        rtn.emplace("highlight/styles/base16/decaf.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLXh6K57B7Mm0XzMAcFFlpl71uOs77OvfD6NfV7hDqxQYpma4nqsNmXuI4UPhqN), "text/css"});
        rtn.emplace("highlight/styles/base16/decaf.min.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr6D0ISFpHpo0xqMhmLSawyCq5EV28sIronFnVpcLwpCp1asrLpZexPOZtGtPcet5A03), "text/css"});
        rtn.emplace("highlight/styles/base16/default-dark.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUU1oKBNuCv8NGIybH2N8XmjJBhLausZ1), "text/css"});
        rtn.emplace("highlight/styles/base16/default-dark.min.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MyGW7VBM1775bV9gGsTCAdB5SxT6EH40g3Ogjo6cLyOgu45ctkVIZTzfjL2XpyTaz399ftTYQAcd), "text/css"});
        rtn.emplace("highlight/styles/base16/default-light.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV1JpVXIM4mpPSsplj6Zia7ST8TUFvQaKjCp9OGGhprzTnL0i5Lua3KMDuLnXHY3b2ZkYPrprf), "text/css"});
        rtn.emplace("highlight/styles/base16/default-light.min.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8YqqCcyksubNH8qdyXguYFtlmZZY9iwSYne1wT8tKMjNx9UtEcC1EgVqeJCsVvxEQ8mQJJPGr1fHZD), "text/css"});
        rtn.emplace("highlight/styles/base16/dirtysea.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUToQOm3w59e9grF6T0ZEBr1zEYCiKNSePcwQah4GYNRttwzjFpImqSGIr8c4ka58KXL), "text/css"});
        rtn.emplace("highlight/styles/base16/dirtysea.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUU1oKBNuCv8NI9eJ7oyLzKejFxAJWUNv), "text/css"});
        rtn.emplace("highlight/styles/base16/dracula.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFtRiDjIxE8aIrkjwud445AET72kdDLtZoJ), "text/css"});
        rtn.emplace("highlight/styles/base16/dracula.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XQatGJpsTKv03ZkU12DAf96oq6JH5n), "text/css"});
        rtn.emplace("highlight/styles/base16/edge-dark.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr6D0ISFpHpo0xqMhmLSawyCq5EV28sIronFnVpcLwpCp1asrLpbJbIkS00AzvR5D4PD), "text/css"});
        rtn.emplace("highlight/styles/base16/edge-dark.min.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV1JpVXIM4mpPSsplj6Zia7ST8TUFvQaKjCp9OGGhprzTnL0i5LuhoVrethnnymIn55c3XRwJP), "text/css"});
        rtn.emplace("highlight/styles/base16/edge-light.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWI944w1PnerFDxvDUyjND), "text/css"});
        rtn.emplace("highlight/styles/base16/edge-light.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg5RsgDTn9lcH9GPl4F9U58nYIzkvl7m1aexCmBAz0Avr1ikw26U8uZZYsEDAaO91ANbLR0yCBP), "text/css"});
        rtn.emplace("highlight/styles/base16/eighties.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUToQOm3w59e9grF6T0ZEBr1zEYCiKNSePcwQah4GYNRttwzjFpInFPCnXmHes3D0KoN), "text/css"});
        rtn.emplace("highlight/styles/base16/eighties.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUU1oKBNuCv8PB7x0SjH7GeBHsyTxVHs3), "text/css"});
        rtn.emplace("highlight/styles/base16/embers.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTCfNfpoaxpqM3mkoU0Sh2B8t), "text/css"});
        rtn.emplace("highlight/styles/base16/embers.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWI94JrMm2kQZeShx9sNO7), "text/css"});
        rtn.emplace("highlight/styles/base16/equilibrium-dark.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MyGW7VBM1775bV9gGsTCAdB5SxT6EH40g3Ogjo6cLyOgu45ctkeYstjnTTTlSjvm1pB83QWQXkPL), "text/css"});
        rtn.emplace("highlight/styles/base16/equilibrium-dark.min.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPczTajTfpZ2Y8GHiVHh3TPTOaE1JDjJEa7LkIEs02WOpbLhGUHGqxaIJj3zoNiczfb1MMs4jKPRwuaEbrv), "text/css"});
        rtn.emplace("highlight/styles/base16/equilibrium-gray-dark.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89ozqBfmWiugWw7F9lB3mLRBNVZtPMh5QD8Ln9JOyAPmX4Dae51Jag1rdS4VE1wH0dkwiIODeGUAsvW8m2br), "text/css"});
        rtn.emplace("highlight/styles/base16/equilibrium-gray-dark.min.css", embedded_file{saucer::stash<>::view(f1XjtLeY7kEHn3uAOla2WtIqkhmArnwhH4LSzKePpbJipdsv3YnYnbu7pu0Pwwl8qOAGdxRfvLaaIcu5W7AYfduzXCtikoBUYrwrz), "text/css"});
        rtn.emplace("highlight/styles/base16/equilibrium-gray-light.css", embedded_file{saucer::stash<>::view(f1MJy0Jkn1m1RgYZLUCWN7S3bzxuaInfbcWEz4OCmjhuOEETywS76R0SOXQ7JUjQtRXhStuavw0cEe9qQtw0MIv6l4G6DNJaN), "text/css"});
        rtn.emplace("highlight/styles/base16/equilibrium-gray-light.min.css", embedded_file{saucer::stash<>::view(f6NJUXPQtyszSa7uwGSoRoLpoqkusAEMgTwdhFGsf45R7EglahgdgqVkMJFj9OceWJmOizSH6n93sudambbbAAAqIXxVIddf0sMUy3), "text/css"});
        rtn.emplace("highlight/styles/base16/equilibrium-light.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8YqqCcyksubNH8qdyXguYFtlmZZY9iwSYne1wT8tKMjNx9UtEcCdU2g96HhityfeYJaAT4QHHaM9uF), "text/css"});
        rtn.emplace("highlight/styles/base16/equilibrium-light.min.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89ozqBfmWiugWw7F9lB3mLRBNVZtPMh5QD8Ln9JOyAPmX4Dae51Jag1rdS4VE1wH0dl4xseiEamRpSSVvmhX), "text/css"});
        rtn.emplace("highlight/styles/base16/espresso.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUToQOm3w59e9grF6T0ZEBr1zEYCiKNSePcwQah4GYNRttwzjFpInGNrADXgX1IMlAzT), "text/css"});
        rtn.emplace("highlight/styles/base16/espresso.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUU1oKBNuCv8PFiIA4dou0aAGNu5gHFkR), "text/css"});
        rtn.emplace("highlight/styles/base16/eva-dim.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFtRiDjIxE8aIrkjwud44BIndWhTXS2iIsN), "text/css"});
        rtn.emplace("highlight/styles/base16/eva-dim.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XQatGJpsTKvSpjPiTMgOy41z9yvw83), "text/css"});
        rtn.emplace("highlight/styles/base16/eva.css", embedded_file{saucer::stash<>::view(f9WyAbPBHunlngqbuiIzAC3zsDdFbI2XIThko3QkMxWyt2kXPYDeRZhYvDReEdfSw7OXNX1), "text/css"});
        rtn.emplace("highlight/styles/base16/eva.min.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFtRiDjIxE8aIrkjwud44BIndcD6PbNPmUd), "text/css"});
        rtn.emplace("highlight/styles/base16/flat.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVNAvEYAwOY5oVTsI4PyUTUIefGgARSnoBPHM9xVIMzrPsCFWA8RsKcIuw4wy3), "text/css"});
        rtn.emplace("highlight/styles/base16/flat.min.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUToQOm3w59e9grF6T0ZEBr1zEYCiKNSePcwQah4GYNRttwzjFpIneeOt7aqJXHqImcl), "text/css"});
        rtn.emplace("highlight/styles/base16/framer.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTCfNfpoaxpqNYJ7eiTDJ2t3T), "text/css"});
        rtn.emplace("highlight/styles/base16/framer.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWI9BJcJhIhchOgeBAus0R), "text/css"});
        rtn.emplace("highlight/styles/base16/fruit-soda.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWI9BJkMPYhkFY5BGApcyB), "text/css"});
        rtn.emplace("highlight/styles/base16/fruit-soda.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg5RsgDTn9lcH9GPl4F9U58nYIzkvl7m1aexCmBAz0Avr1ikw26Ugqfb38u53GbJKxUv3BUlSBH), "text/css"});
        rtn.emplace("highlight/styles/base16/gigavolt.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUToQOm3w59e9grF6T0ZEBr1zEYCiKNSePcwQah4GYNRttwzjFpIo3Jc5U0cWJswHztL), "text/css"});
        rtn.emplace("highlight/styles/base16/gigavolt.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUU1oKBNuCv8Sx6zpSDiMxlRjnZGATPnv), "text/css"});
        rtn.emplace("highlight/styles/base16/github.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTCfNfpoaxpqOxtV8rDA375vP), "text/css"});
        rtn.emplace("highlight/styles/base16/github.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWI9HwEk4etVJTV6h25AiB), "text/css"});
        rtn.emplace("highlight/styles/base16/google-dark.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XQatGJpsTKwMjVHU3anMJhEj7t30iJ), "text/css"});
        rtn.emplace("highlight/styles/base16/google-dark.min.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYTmV7mJf0yKc2oFmMLWZADEKbeQzmUa6IZN6Skw9Lsj8sx6nncgqqBwYdzuA1ZBakWwSvEubfqhn), "text/css"});
        rtn.emplace("highlight/styles/base16/google-light.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUU1oKBNuCv8SzrtAC6pvqzqL55xHRUDz), "text/css"});
        rtn.emplace("highlight/styles/base16/google-light.min.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MyGW7VBM1775bV9gGsTCAdB5SxT6EH40g3Ogjo6cLyOgu45ctkwBVJn39btboo5ApRumlmYSP2sV), "text/css"});
        rtn.emplace("highlight/styles/base16/grayscale-dark.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg5RsgDTn9lcH9GPl4F9U58nYIzkvl7m1aexCmBAz0Avr1ikw26VD0edegKXh3B54Ev8Lm8kYlv), "text/css"});
        rtn.emplace("highlight/styles/base16/grayscale-dark.min.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVLuBY8wrajiK6mXN3z7BVReHIYsn29ZNvgzI1QKiS5rOuFDY4Lp3Dc83JPDrRCCJGApbMcXoQVQ4wIF), "text/css"});
        rtn.emplace("highlight/styles/base16/grayscale-light.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYTmV7mJf0yKc2oFmMLWZADEKbeQzmUa6IZN6Skw9Lsj8sx6nncgqrihnjymp7l7kyM7ikgA7G78t), "text/css"});
        rtn.emplace("highlight/styles/base16/grayscale-light.min.css", embedded_file{saucer::stash<>::view(f1CGTDaSS4GQFtSRzgyx3Hgl120PnESLfVqAJQe2EStW6oDV4PsjXY0CUqEpwfy6nIDRFg89EeIN2sIwUypeydeYa07O7), "text/css"});
        rtn.emplace("highlight/styles/base16/green-screen.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUU1oKBNuCv8T1DmcwbMToYxkYP22lyOB), "text/css"});
        rtn.emplace("highlight/styles/base16/green-screen.min.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MyGW7VBM1775bV9gGsTCAdB5SxT6EH40g3Ogjo6cLyOgu45ctkwHqd1lNEiDfx3RBvJFd1bdxrrH), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-dark-hard.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8YqqCcyksubNH8qdyXguYFtlmZZY9iwSYne1wT8tKMjNx9UtEcDogFjIQL0ZkwdAcPMmNluxaF8gr5), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-dark-hard.min.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89ozqBfmWiugWw7F9lB3mLRBNVZtPMh5QD8Ln9JOyAPmX4Dae51P7ppvCO6vS08PJ9WzCd5bhgWWTsIe3sYt), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-dark-medium.css", embedded_file{saucer::stash<>::view(f1CGTDaSS4GQFtSRzgyx3Hgl120PnESLfVqAJQe2EStW6oDV4PsjXY0CUqEpwfy6nTzXkZd1VcV5hJ9iIw0CuDFsF1HeN), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-dark-medium.min.css", embedded_file{saucer::stash<>::view(f5cARlJZCRKHyJijwihhfSlqutrNdtd5nL37sA7wnEjIq2lnndM5KZVtFJzqCUv7POzrq3SrgFDLkM7h2if73y588MpiWtX9E3), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-dark-pale.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8YqqCcyksubNH8qdyXguYFtlmZZY9iwSYne1wT8tKMjNx9UtEcDogFjIQL0ZkwdAcPMn4M5GKLN4aJ), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-dark-pale.min.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89ozqBfmWiugWw7F9lB3mLRBNVZtPMh5QD8Ln9JOyAPmX4Dae51P7ppvCO6vS08PJ9WzFqj6FCn1K1BxmYBn), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-dark-soft.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8YqqCcyksubNH8qdyXguYFtlmZZY9iwSYne1wT8tKMjNx9UtEcDogFjIQL0ZkwdAcPMnKcAxibmnJ5), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-dark-soft.min.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89ozqBfmWiugWw7F9lB3mLRBNVZtPMh5QD8Ln9JOyAPmX4Dae51P7ppvCO6vS08PJ9WzH4xBWzWU7g9wfiMt), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-light-hard.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVLuBY8wrajiK6mXN3z7BVReHIYsn29ZNvgzI1QKiS5rOuFDY4Lp3GSx24kkNejCas30rONTTxNY2M2l), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-light-hard.min.css", embedded_file{saucer::stash<>::view(f1MJy0Jkn1m1RgYZLUCWN7S3bzxuaInfbcWEz4OCmjhuOEETywS76R0SOXQ7JUjnkM2OB9YbDgj5E8c72scCiSnt3URSmDxRb), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-light-medium.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPczTajTfpZ2Y8GHiVHh3TPTOaE1JDjJEa7LkIEs02WOpbLhGUHIC4Jq7MJ78Eo7xB0d7mPg9twqodq0h3j), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-light-medium.min.css", embedded_file{saucer::stash<>::view(fNBb8dMnLMpmD3QjiSaSJCnaUwePcjhPviuuVdoolIp3mtRNcwVC0wdg7GZLXbfqatDSIwJBfZrzaDK3MtcvHXU8Vc6Ka0z617T), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-light-soft.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVLuBY8wrajiK6mXN3z7BVReHIYsn29ZNvgzI1QKiS5rOuFDY4Lp3GSx24kkNejCas30rPKJjxVugSUl), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-light-soft.min.css", embedded_file{saucer::stash<>::view(f1MJy0Jkn1m1RgYZLUCWN7S3bzxuaInfbcWEz4OCmjhuOEETywS76R0SOXQ7JUjnkM2OB9YbDgj5E8c72x44II6t18FK4pnFb), "text/css"});
        rtn.emplace("highlight/styles/base16/hardcore.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUToQOm3w59e9grF6T0ZEBr1zEYCiKNSePcwQah4GYNRttwzjFpIoRUjA4oT4WF2L7BL), "text/css"});
        rtn.emplace("highlight/styles/base16/hardcore.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUU1oKBNuCv8UmT4C0pPO9udeKGcpRMxv), "text/css"});
        rtn.emplace("highlight/styles/base16/harmonic16-dark.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYTmV7mJf0yKc2oFmMLWZADEKbeQzmUa6IZN6Skw9Lsj8sx6nncgsrlfDlfG5aW4FI8EJioS82GBP), "text/css"});
        rtn.emplace("highlight/styles/base16/harmonic16-dark.min.css", embedded_file{saucer::stash<>::view(f1CGTDaSS4GQFtSRzgyx3Hgl120PnESLfVqAJQe2EStW6oDV4PsjXY0CUqEpwfyGAqZj8itOsSH1WW52CshWYBzGTcvkB), "text/css"});
        rtn.emplace("highlight/styles/base16/harmonic16-light.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MyGW7VBM1775bV9gGsTCAdB5SxT6EH40g3Ogjo6cLyOgu45ctl4Y0oCqoMR4mPX8updFJ5XALMMl), "text/css"});
        rtn.emplace("highlight/styles/base16/harmonic16-light.min.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPczTajTfpZ2Y8GHiVHh3TPTOaE1JDjJEa7LkIEs02WOpbLhGUHIomn5WO1MkiqkIIToJKcZ8uXvArELqjb), "text/css"});
        rtn.emplace("highlight/styles/base16/heetch-dark.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XQatGJpsTKwnxKPJCoAZU8qAAdibEh), "text/css"});
        rtn.emplace("highlight/styles/base16/heetch-dark.min.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYTmV7mJf0yKc2oFmMLWZADEKbeQzmUa6IZN6Skw9Lsj8sx6nncgstoiVhDW04pY9gKm9d8pB8HRL), "text/css"});
        rtn.emplace("highlight/styles/base16/heetch-light.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUU1oKBNuCv8UoGyGVIt9hMyJelJzAHx5), "text/css"});
        rtn.emplace("highlight/styles/base16/heetch-light.min.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MyGW7VBM1775bV9gGsTCAdB5SxT6EH40g3Ogjo6cLyOgu45ctl4gTPmsRo8XINFPVDL82e8rnQwt), "text/css"});
        rtn.emplace("highlight/styles/base16/helios.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTCfNfpoaxpqQPDSRNVTwOlkJ), "text/css"});
        rtn.emplace("highlight/styles/base16/helios.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWI9OgzVWiAnh6AohjfGpn), "text/css"});
        rtn.emplace("highlight/styles/base16/hopscotch.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr6D0ISFpHpo0xqMhmLSawyCq5EV28sIronFnVpcLwpCp1asrLpgNA3bRaT85QHPwwj5), "text/css"});
        rtn.emplace("highlight/styles/base16/hopscotch.min.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV1JpVXIM4mpPSsplj6Zia7ST8TUFvQaKjCp9OGGhprzTnL0i5Lv5WX1eB7EWfbSc2NAPcRM2t), "text/css"});
        rtn.emplace("highlight/styles/base16/horizon-dark.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUU1oKBNuCv8UsrkJHF9RNI3sOibM7tKt), "text/css"});
        rtn.emplace("highlight/styles/base16/horizon-dark.min.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MyGW7VBM1775bV9gGsTCAdB5SxT6EH40g3Ogjo6cLyOgu45ctl520TxPYN4XNJceX2zUefCXhYA7), "text/css"});
        rtn.emplace("highlight/styles/base16/horizon-light.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV1JpVXIM4mpPSsplj6Zia7ST8TUFvQaKjCp9OGGhprzTnL0i5Lv5WXvDbCYz2DQWQKvdLb1Wd), "text/css"});
        rtn.emplace("highlight/styles/base16/horizon-light.min.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8YqqCcyksubNH8qdyXguYFtlmZZY9iwSYne1wT8tKMjNx9UtEcEOmHzhJVvGk1cXon9mPwKKc3QTp5), "text/css"});
        rtn.emplace("highlight/styles/base16/humanoid-dark.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV1JpVXIM4mpPSsplj6Zia7ST8TUFvQaKjCp9OGGhprzTnL0i5Lv5hpZnqSfuZkdLWPL4PqgyJ), "text/css"});
        rtn.emplace("highlight/styles/base16/humanoid-dark.min.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8YqqCcyksubNH8qdyXguYFtlmZZY9iwSYne1wT8tKMjNx9UtEcEPdC4y9p8eeiQBXfmrO8BSq8vfjn), "text/css"});
        rtn.emplace("highlight/styles/base16/humanoid-light.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg5RsgDTn9lcH9GPl4F9U58nYIzkvl7m1aexCmBAz0Avr1ikw26VjYyxpocP3bcbJNctlciZyHz), "text/css"});
        rtn.emplace("highlight/styles/base16/humanoid-light.min.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVLuBY8wrajiK6mXN3z7BVReHIYsn29ZNvgzI1QKiS5rOuFDY4LrVppsWOZ9js7dTBFyRs99lI7ljl8V), "text/css"});
        rtn.emplace("highlight/styles/base16/ia-dark.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFtRiDjIxE8aIrkjwud44YycSvuGadq008Z), "text/css"});
        rtn.emplace("highlight/styles/base16/ia-dark.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XQatGJpsTKxFp5cVHpu3DU2S5tIlUp), "text/css"});
        rtn.emplace("highlight/styles/base16/ia-light.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUToQOm3w59e9grF6T0ZEBr1zEYCiKNSePcwQah4GYNRttwzjFpIoqQIsJc8m3sh16e3), "text/css"});
        rtn.emplace("highlight/styles/base16/ia-light.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUU1oKBNuCv8WfKxQKhrk8iBOYD9F5XKl), "text/css"});
        rtn.emplace("highlight/styles/base16/icy-dark.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUToQOm3w59e9grF6T0ZEBr1zEYCiKNSePcwQah4GYNRttwzjFpIoqeBBWZTKo4Z3H0N), "text/css"});
        rtn.emplace("highlight/styles/base16/icy-dark.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUU1oKBNuCv8WgO0gUr0VM2TDTS9xrMe3), "text/css"});
        rtn.emplace("highlight/styles/base16/ir-black.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUToQOm3w59e9grF6T0ZEBr1zEYCiKNSePcwQah4GYNRttwzjFpIos52wq5he4kVOpHP), "text/css"});
        rtn.emplace("highlight/styles/base16/ir-black.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUU1oKBNuCv8Wn6dH8kG6ZkBYUKhoKM8B), "text/css"});
        rtn.emplace("highlight/styles/base16/isotope.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFtRiDjIxE8aIrkjwud44ZPLOx04ZKYboxf), "text/css"});
        rtn.emplace("highlight/styles/base16/isotope.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XQatGJpsTKxHqNa8qAuKS7kAFEuNxD), "text/css"});
        rtn.emplace("highlight/styles/base16/kimber.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTCfNfpoaxpqUot87EtCOoC4R), "text/css"});
        rtn.emplace("highlight/styles/base16/kimber.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWI9jO0U5PLv29flmaYngJ), "text/css"});
        rtn.emplace("highlight/styles/base16/london-tube.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XQatGJpsTKyeP2bMzoRLqEiRvDADfn), "text/css"});
        rtn.emplace("highlight/styles/base16/london-tube.min.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYTmV7mJf0yKc2oFmMLWZADEKbeQzmUa6IZN6Skw9Lsj8sx6nnch1YMTbJMUm6u9DH52vSvX5sSLj), "text/css"});
        rtn.emplace("highlight/styles/base16/macintosh.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr6D0ISFpHpo0xqMhmLSawyCq5EV28sIronFnVpcLwpCp1asrLpoahhP3OZkdREi9K0h), "text/css"});
        rtn.emplace("highlight/styles/base16/macintosh.min.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV1JpVXIM4mpPSsplj6Zia7ST8TUFvQaKjCp9OGGhprzTnL0i5Lvi3LLvpmTwzwGhg1CXD8SXL), "text/css"});
        rtn.emplace("highlight/styles/base16/marrakesh.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr6D0ISFpHpo0xqMhmLSawyCq5EV28sIronFnVpcLwpCp1asrLpoajAGr7SRKxkax6f5), "text/css"});
        rtn.emplace("highlight/styles/base16/marrakesh.min.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV1JpVXIM4mpPSsplj6Zia7ST8TUFvQaKjCp9OGGhprzTnL0i5Lvi3SDvwCzjqswf8wDK7PDmt), "text/css"});
        rtn.emplace("highlight/styles/base16/materia.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFtRiDjIxE8aIrkjwud44x9saoMjvoVj2gt), "text/css"});
        rtn.emplace("highlight/styles/base16/materia.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XQatGJpsTKz5BqQRrmiQGLshzAEPa7), "text/css"});
        rtn.emplace("highlight/styles/base16/material-darker.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYTmV7mJf0yKc2oFmMLWZADEKbeQzmUa6IZN6Skw9Lsj8sx6nnch3ZwZUC9JgW4T0QSSz11ujvwiR), "text/css"});
        rtn.emplace("highlight/styles/base16/material-darker.min.css", embedded_file{saucer::stash<>::view(f1CGTDaSS4GQFtSRzgyx3Hgl120PnESLfVqAJQe2EStW6oDV4PsjXY0CUqEpwfz4ObQt42ZJRTntCzekbOqbBQKYBlYGJ), "text/css"});
        rtn.emplace("highlight/styles/base16/material-lighter.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MyGW7VBM1775bV9gGsTCAdB5SxT6EH40g3Ogjo6cLyOgu45ctlmmPqWgATHYQSYIbYiDxsveMBZT), "text/css"});
        rtn.emplace("highlight/styles/base16/material-lighter.min.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPczTajTfpZ2Y8GHiVHh3TPTOaE1JDjJEa7LkIEs02WOpbLhGUHMA9aZ1MgboHT7fVxWBiRBi1skPkvUG4R), "text/css"});
        rtn.emplace("highlight/styles/base16/material-palenight.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVLuBY8wrajiK6mXN3z7BVReHIYsn29ZNvgzI1QKiS5rOuFDY4M3UB0DKpxtZEUKEcycSC3MGMr0udZz), "text/css"});
        rtn.emplace("highlight/styles/base16/material-palenight.min.css", embedded_file{saucer::stash<>::view(f1MJy0Jkn1m1RgYZLUCWN7S3bzxuaInfbcWEz4OCmjhuOEETywS76R0SOXQ7JUktPpogFPp9zRSZcDgjWSZrDFXZffh5qPuIV), "text/css"});
        rtn.emplace("highlight/styles/base16/material-vivid.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg5RsgDTn9lcH9GPl4F9U58nYIzkvl7m1aexCmBAz0Avr1ikw26YHuKDboh23tKgp3YSvkPejKN), "text/css"});
        rtn.emplace("highlight/styles/base16/material-vivid.min.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVLuBY8wrajiK6mXN3z7BVReHIYsn29ZNvgzI1QKiS5rOuFDY4M3UB0DKpxtZEUUG6KXcZBhb1Ngb3w3), "text/css"});
        rtn.emplace("highlight/styles/base16/material.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUToQOm3w59e9grF6T0ZEBr1zEYCiKNSePcwQah4GYNRttwzjFpIqSGnPzxtenEgywol), "text/css"});
        rtn.emplace("highlight/styles/base16/material.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUU1oKBNuCv8eDQuTD459mKnN3zdKjcXb), "text/css"});
        rtn.emplace("highlight/styles/base16/mellow-purple.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV1JpVXIM4mpPSsplj6Zia7ST8TUFvQaKjCp9OGGhprzTnL0i5LviAxRMsqn6wszloI86lhcOp), "text/css"});
        rtn.emplace("highlight/styles/base16/mellow-purple.min.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8YqqCcyksubNH8qdyXguYFtlmZZY9iwSYne1wT8tKMjNx9UtEcHJz1YFUWs5qfm3dF8KEWmz1u2Fdr), "text/css"});
        rtn.emplace("highlight/styles/base16/mexico-light.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUU1oKBNuCv8eFGgsNT0Xgy0EkRMiMzYp), "text/css"});
        rtn.emplace("highlight/styles/base16/mexico-light.min.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MyGW7VBM1775bV9gGsTCAdB5SxT6EH40g3Ogjo6cLyOgu45ctlmv1GdIJjh1WCk9QCSKWCVubgHr), "text/css"});
        rtn.emplace("highlight/styles/base16/mocha.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLXh6K57B7Mm0XzMAcFFlpl71uOs77OvfD6NfV7hDqxQYpma4nqvaRujus7QAKJ), "text/css"});
        rtn.emplace("highlight/styles/base16/mocha.min.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr6D0ISFpHpo0xqMhmLSawyCq5EV28sIronFnVpcLwpCp1asrLpogL4Eore1ChNTDp9n), "text/css"});
        rtn.emplace("highlight/styles/base16/monokai.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFtRiDjIxE8aIrkjwud44xUKzbcVjqlAoS3), "text/css"});
        rtn.emplace("highlight/styles/base16/monokai.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XQatGJpsTKz6jksDUwJ1fTIs13I2Yl), "text/css"});
        rtn.emplace("highlight/styles/base16/nebula.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTCfNfpoaxpqZBhx08m4G24jD), "text/css"});
        rtn.emplace("highlight/styles/base16/nebula.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWIA3reM4qfvfM3RmPdpbP), "text/css"});
        rtn.emplace("highlight/styles/base16/nord.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVNAvEYAwOY5oVTsI4PyUTUIefGgARSnoBPHM9xVIMzrPsCFWA8SYylYAm4fsR), "text/css"});
        rtn.emplace("highlight/styles/base16/nord.min.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUToQOm3w59e9grF6T0ZEBr1zEYCiKNSePcwQah4GYNRttwzjFpIqsaZ8bWan2kYUOuJ), "text/css"});
        rtn.emplace("highlight/styles/base16/nova.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVNAvEYAwOY5oVTsI4PyUTUIefGgARSnoBPHM9xVIMzrPsCFWA8SYymnNNHtYJ), "text/css"});
        rtn.emplace("highlight/styles/base16/nova.min.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUToQOm3w59e9grF6T0ZEBr1zEYCiKNSePcwQah4GYNRttwzjFpIqsaeyXouJAr5pS3n), "text/css"});
        rtn.emplace("highlight/styles/base16/ocean.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLXh6K57B7Mm0XzMAcFFlpl71uOs77OvfD6NfV7hDqxQYpma4nqwHNRYVDYxjHv), "text/css"});
        rtn.emplace("highlight/styles/base16/ocean.min.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr6D0ISFpHpo0xqMhmLSawyCq5EV28sIronFnVpcLwpCp1asrLprvaiIPAHitaAMhoMF), "text/css"});
        rtn.emplace("highlight/styles/base16/oceanicnext.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XQatGJpsTL004amNF1TGXUNqrdeEsN), "text/css"});
        rtn.emplace("highlight/styles/base16/oceanicnext.min.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYTmV7mJf0yKc2oFmMLWZADEKbeQzmUa6IZN6Skw9Lsj8sx6nnch7scURiUlB7Tv1qwfV1jKbtg83), "text/css"});
        rtn.emplace("highlight/styles/base16/one-light.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr6D0ISFpHpo0xqMhmLSawyCq5EV28sIronFnVpcLwpCp1asrLps01CJamsStQfO2n9n), "text/css"});
        rtn.emplace("highlight/styles/base16/one-light.min.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV1JpVXIM4mpPSsplj6Zia7ST8TUFvQaKjCp9OGGhprzTnL0i5Lvy218CZF9ZNO4k5YTbmWYHj), "text/css"});
        rtn.emplace("highlight/styles/base16/onedark.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFtRiDjIxE8aIrkjwud459YFVwJVtZQhhEx), "text/css"});
        rtn.emplace("highlight/styles/base16/onedark.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XQatGJpsTL01I4n7smO5jQHCrcsaYN), "text/css"});
        rtn.emplace("highlight/styles/base16/outrun-dark.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XQatGJpsTL024VzNnUJN3jW29M66WB), "text/css"});
        rtn.emplace("highlight/styles/base16/outrun-dark.min.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYTmV7mJf0yKc2oFmMLWZADEKbeQzmUa6IZN6Skw9Lsj8sx6nnch81zSTleYDC7SeYSzPkyU2lwNH), "text/css"});
        rtn.emplace("highlight/styles/base16/papercolor-dark.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYTmV7mJf0yKc2oFmMLWZADEKbeQzmUa6IZN6Skw9Lsj8sx6nnchA0RGTYad7yieq4UhxYhw59ERf), "text/css"});
        rtn.emplace("highlight/styles/base16/papercolor-dark.min.css", embedded_file{saucer::stash<>::view(f1CGTDaSS4GQFtSRzgyx3Hgl120PnESLfVqAJQe2EStW6oDV4PsjXY0CUqEpwfzYWo5vTdJOf4uJdtzjJbMUtE9DoFptD), "text/css"});
        rtn.emplace("highlight/styles/base16/papercolor-light.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MyGW7VBM1775bV9gGsTCAdB5SxT6EH40g3Ogjo6cLyOgu45ctmDJoa22pFYwiOd0be1jaBDF8BUp), "text/css"});
        rtn.emplace("highlight/styles/base16/papercolor-light.min.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPczTajTfpZ2Y8GHiVHh3TPTOaE1JDjJEa7LkIEs02WOpbLhGUHOAZSqTKMK5pcGX6yYPKMyK3OqHqOzg1r), "text/css"});
        rtn.emplace("highlight/styles/base16/paraiso.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFtRiDjIxE8aIrkjwud45FI0aynMBk5Oo8h), "text/css"});
        rtn.emplace("highlight/styles/base16/paraiso.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XQatGJpsTL0SBvg1RIKhBGJ49Htx3L), "text/css"});
        rtn.emplace("highlight/styles/base16/pasque.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTCfNfpoaxpqc5obrUrTUbgEF), "text/css"});
        rtn.emplace("highlight/styles/base16/pasque.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWIAHU1Jk644aEo9nC1jzX), "text/css"});
        rtn.emplace("highlight/styles/base16/phd.css", embedded_file{saucer::stash<>::view(f9WyAbPBHunlngqbuiIzAC3zsDdFbI2XIThko3QkMxWyt2kXPYDeRZhYvDReEdtZm73Pe7P), "text/css"});
        rtn.emplace("highlight/styles/base16/phd.min.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFtRiDjIxE8aIrkjwud45FSAonzO3mqnhUB), "text/css"});
        rtn.emplace("highlight/styles/base16/pico.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVNAvEYAwOY5oVTsI4PyUTUIefGgARSnoBPHM9xVIMzrPsCFWA8SjV0MCDxeeh), "text/css"});
        rtn.emplace("highlight/styles/base16/pico.min.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUToQOm3w59e9grF6T0ZEBr1zEYCiKNSePcwQah4GYNRttwzjFpIrfuMIDt2NwSS3X7L), "text/css"});
        rtn.emplace("highlight/styles/base16/pop.css", embedded_file{saucer::stash<>::view(f9WyAbPBHunlngqbuiIzAC3zsDdFbI2XIThko3QkMxWyt2kXPYDeRZhYvDReEdtbyWTVl9n), "text/css"});
        rtn.emplace("highlight/styles/base16/pop.min.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFtRiDjIxE8aIrkjwud45FcUKSIw3mG0QHj), "text/css"});
        rtn.emplace("highlight/styles/base16/porple.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTCfNfpoaxpqcAmE46jd3A7s3), "text/css"});
        rtn.emplace("highlight/styles/base16/porple.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWIAHrHT4jeiAR0vtyIKEl), "text/css"});
        rtn.emplace("highlight/styles/base16/qualia.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTCfNfpoaxpqdfdCAoPp57a3n), "text/css"});
        rtn.emplace("highlight/styles/base16/qualia.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWIAOsb00jBd5eId0LqXtj), "text/css"});
        rtn.emplace("highlight/styles/base16/railscasts.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWIAVCrZLhGyX75iGeecGx), "text/css"});
        rtn.emplace("highlight/styles/base16/railscasts.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg5RsgDTn9lcH9GPl4F9U58nYIzkvl7m1aexCmBAz0Avr1ikw26askwpbKVZJnnEs4efwg3CegN), "text/css"});
        rtn.emplace("highlight/styles/base16/rebecca.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFtRiDjIxE8aIrkjwud45RTCPXah5P21uK3), "text/css"});
        rtn.emplace("highlight/styles/base16/rebecca.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XQatGJpsTL1NINKPRJfnMGzXnXus2l), "text/css"});
        rtn.emplace("highlight/styles/base16/ros-pine-dawn.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV1JpVXIM4mpPSsplj6Zia7ST8TUFvQaKjCp9OGGhprzTnL0i5LwLRCd2x4Wa1IXNh8gIuQuqB), "text/css"});
        rtn.emplace("highlight/styles/base16/ros-pine-dawn.min.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8YqqCcyksubNH8qdyXguYFtlmZZY9iwSYne1wT8tKMjNx9UtEcKI37xUKuJlkSsmyCWnPNNrbgh3fH), "text/css"});
        rtn.emplace("highlight/styles/base16/ros-pine-moon.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV1JpVXIM4mpPSsplj6Zia7ST8TUFvQaKjCp9OGGhprzTnL0i5LwLRCd2x4Wa1IY9tMrxKIf59), "text/css"});
        rtn.emplace("highlight/styles/base16/ros-pine-moon.min.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8YqqCcyksubNH8qdyXguYFtlmZZY9iwSYne1wT8tKMjNx9UtEcKI37xUKuJlkSwQvSn14RpWoUPSF9), "text/css"});
        rtn.emplace("highlight/styles/base16/ros-pine.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUToQOm3w59e9grF6T0ZEBr1zEYCiKNSePcwQah4GYNRttwzjFpIsUPOwmjaKWaOOh6J), "text/css"});
        rtn.emplace("highlight/styles/base16/ros-pine.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUU1oKBNuCv8nkn4c0k8rHkiav8Lx5EFn), "text/css"});
        rtn.emplace("highlight/styles/base16/sagelight.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr6D0ISFpHpo0xqMhmLSawyCq5EV28sIronFnVpcLwpCp1asrLpyYwpExYc8n19n7tCt), "text/css"});
        rtn.emplace("highlight/styles/base16/sagelight.min.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV1JpVXIM4mpPSsplj6Zia7ST8TUFvQaKjCp9OGGhprzTnL0i5LwSnlO6lVcuCrZanzS8xjze7), "text/css"});
        rtn.emplace("highlight/styles/base16/sandcastle.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWIAc4Li9wdZWkVjvdIFVr), "text/css"});
        rtn.emplace("highlight/styles/base16/sandcastle.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg5RsgDTn9lcH9GPl4F9U58nYIzkvl7m1aexCmBAz0Avr1ikw26bOvgs1H1EJFFZhkN4PIuzcTz), "text/css"});
        rtn.emplace("highlight/styles/base16/seti-ui.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFtRiDjIxE8aIrkjwud45XW12J7z3yxrRcB), "text/css"});
        rtn.emplace("highlight/styles/base16/seti-ui.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XQatGJpsTL1pdZT4bp2nLosCaiMSlH), "text/css"});
        rtn.emplace("highlight/styles/base16/shapeshifter.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUU1oKBNuCv8paYIP1QD59EGQgwPHk31f), "text/css"});
        rtn.emplace("highlight/styles/base16/shapeshifter.min.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MyGW7VBM1775bV9gGsTCAdB5SxT6EH40g3Ogjo6cLyOgu45ctme67T9ueMtxuIMHq9W59iHn84DD), "text/css"});
        rtn.emplace("highlight/styles/base16/silk-dark.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr6D0ISFpHpo0xqMhmLSawyCq5EV28sIronFnVpcLwpCp1asrLpycAxEGacmq4922sJH), "text/css"});
        rtn.emplace("highlight/styles/base16/silk-dark.min.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV1JpVXIM4mpPSsplj6Zia7ST8TUFvQaKjCp9OGGhprzTnL0i5LwT2tcbqwuF5NVXyzb3Deyhf), "text/css"});
        rtn.emplace("highlight/styles/base16/silk-light.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWIAcHdEYuY4fTFsgQsmrj), "text/css"});
        rtn.emplace("highlight/styles/base16/silk-light.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg5RsgDTn9lcH9GPl4F9U58nYIzkvl7m1aexCmBAz0Avr1ikw26bPvxfQIqZkVdlgpClC7Io4LT), "text/css"});
        rtn.emplace("highlight/styles/base16/snazzy.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTCfNfpoaxpqgYeSs971BDNmF), "text/css"});
        rtn.emplace("highlight/styles/base16/snazzy.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWIAcPs1pbU9iP5cAG78BX), "text/css"});
        rtn.emplace("highlight/styles/base16/solar-flare-light.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8YqqCcyksubNH8qdyXguYFtlmZZY9iwSYne1wT8tKMjNx9UtEcKsZZd2nTaWZEiAWaCcsXxOsq8veV), "text/css"});
        rtn.emplace("highlight/styles/base16/solar-flare-light.min.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89ozqBfmWiugWw7F9lB3mLRBNVZtPMh5QD8Ln9JOyAPmX4Dae51wEjtthvueRP6yVvAvlx15pxR50Yex5gmZ), "text/css"});
        rtn.emplace("highlight/styles/base16/solar-flare.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XQatGJpsTL1qjyf4Ei8IoV7DQRLpPH), "text/css"});
        rtn.emplace("highlight/styles/base16/solar-flare.min.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYTmV7mJf0yKc2oFmMLWZADEKbeQzmUa6IZN6Skw9Lsj8sx6nnchGYCLcexG33I9wj5aHUdnmlx5f), "text/css"});
        rtn.emplace("highlight/styles/base16/solarized-dark.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg5RsgDTn9lcH9GPl4F9U58nYIzkvl7m1aexCmBAz0Avr1ikw26bQghzBsi9YpO0kDjkT7CIpbX), "text/css"});
        rtn.emplace("highlight/styles/base16/solarized-dark.min.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVLuBY8wrajiK6mXN3z7BVReHIYsn29ZNvgzI1QKiS5rOuFDY4MIDKt7DfqGPGmQ9gxwvcuVREOEACyh), "text/css"});
        rtn.emplace("highlight/styles/base16/solarized-light.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYTmV7mJf0yKc2oFmMLWZADEKbeQzmUa6IZN6Skw9Lsj8sx6nnchGYCLcf3uJToB97hEi8z6mlcFn), "text/css"});
        rtn.emplace("highlight/styles/base16/solarized-light.min.css", embedded_file{saucer::stash<>::view(f1CGTDaSS4GQFtSRzgyx3Hgl120PnESLfVqAJQe2EStW6oDV4PsjXY0CUqEpwg03D4FZoSlnkLHwDMvkke5pArcrNl0fj), "text/css"});
        rtn.emplace("highlight/styles/base16/spacemacs.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr6D0ISFpHpo0xqMhmLSawyCq5EV28sIronFnVpcLwpCp1asrLpyeyYzgHMLzvO9SBaV), "text/css"});
        rtn.emplace("highlight/styles/base16/spacemacs.min.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV1JpVXIM4mpPSsplj6Zia7ST8TUFvQaKjCp9OGGhprzTnL0i5LwTG1Wk9NlT2h9bgseu8RwWZ), "text/css"});
        rtn.emplace("highlight/styles/base16/summercamp.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWIAcba7D2TncqZGzhVpnn), "text/css"});
        rtn.emplace("highlight/styles/base16/summercamp.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg5RsgDTn9lcH9GPl4F9U58nYIzkvl7m1aexCmBAz0Avr1ikw26bRRULrGNuQ3VgG3s14YkaSrj), "text/css"});
        rtn.emplace("highlight/styles/base16/summerfruit-dark.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MyGW7VBM1775bV9gGsTCAdB5SxT6EH40g3Ogjo6cLyOgu45ctmeY4XLdm4Ugi0RHlBf0y5SI5aLL), "text/css"});
        rtn.emplace("highlight/styles/base16/summerfruit-dark.min.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPczTajTfpZ2Y8GHiVHh3TPTOaE1JDjJEa7LkIEs02WOpbLhGUHQEEGaDaV8mF1TioUzMAkvBJXi2pVVBbv), "text/css"});
        rtn.emplace("highlight/styles/base16/summerfruit-light.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8YqqCcyksubNH8qdyXguYFtlmZZY9iwSYne1wT8tKMjNx9UtEcKtQgjhMEUYiLhofKszroNICg4bOF), "text/css"});
        rtn.emplace("highlight/styles/base16/summerfruit-light.min.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89ozqBfmWiugWw7F9lB3mLRBNVZtPMh5QD8Ln9JOyAPmX4Dae51wIkuTY6iaFC26j2WAh4dAo9CYHtUyNMdX), "text/css"});
        rtn.emplace("highlight/styles/base16/synth-midnight-terminal-dark.css", embedded_file{saucer::stash<>::view(f1khg4GZgTGpTaGq9zAZkzmJt9b3Z7GBFCztgfYlIRs0pTFfakHzM2kcwNqxlGiQ3t78HjH9sF57JOJ9r8bl8vEWVRp5dP57pKIPRBL5n), "text/css"});
        rtn.emplace("highlight/styles/base16/synth-midnight-terminal-dark.min.css", embedded_file{saucer::stash<>::view(f8DccIUzro7KVtoxwCwWLVgqKoVzSzq45AB1DsuB7mPvxxJk09nhsMlHs4oB8ohFKSLfF3RYSJ33NCG7sf4JU8sVGlJD3oQU3tNnVrszzCfy1j), "text/css"});
        rtn.emplace("highlight/styles/base16/synth-midnight-terminal-light.css", embedded_file{saucer::stash<>::view(f7EqLhcRLMrUY9lXNEZfe35W7jd0izyoQnfZwBbXIB51QWmhjj8HL1MWn4UglB1Pc3ZSDCwqlyH8C4N6hPXueqJyDqsxGhc0pk4mQDpdBr), "text/css"});
        rtn.emplace("highlight/styles/base16/synth-midnight-terminal-light.min.css", embedded_file{saucer::stash<>::view(fXwFS8NzSAwGhiURULRdYoqu5wa5njKyrK1V3Khxw7v5LYvVweTFATzFnHrC0PKZIT3SIADmGsebvmcaXhZoSSf37DLJvkQheI6xs5rW9XEtHBz), "text/css"});
        rtn.emplace("highlight/styles/base16/tango.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLXh6K57B7Mm0XzMAcFFlpl71uOs77OvfD6NfV7hDqxQYpma4nqy36OYaXzHy1T), "text/css"});
        rtn.emplace("highlight/styles/base16/tango.min.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr6D0ISFpHpo0xqMhmLSawyCq5EV28sIronFnVpcLwpCp1asrLq0Dzxt3CgTwYGhMnsR), "text/css"});
        rtn.emplace("highlight/styles/base16/tender.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTCfNfpoaxpqhyEK42PO0hNHH), "text/css"});
        rtn.emplace("highlight/styles/base16/tender.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWIAj2S0o7S7lE4Ag8maZf), "text/css"});
        rtn.emplace("highlight/styles/base16/tomorrow-night.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg5RsgDTn9lcH9GPl4F9U58nYIzkvl7m1aexCmBAz0Avr1ikw26bwrKdiqyM4kxiQqfedAN0pRj), "text/css"});
        rtn.emplace("highlight/styles/base16/tomorrow-night.min.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVLuBY8wrajiK6mXN3z7BVReHIYsn29ZNvgzI1QKiS5rOuFDY4MKe9ypCBUDEbFh1oScP4hjeRL2XCfT), "text/css"});
        rtn.emplace("highlight/styles/base16/tomorrow.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUToQOm3w59e9grF6T0ZEBr1zEYCiKNSePcwQah4GYNRttwzjFpItIJfs64EB0BwePy7), "text/css"});
        rtn.emplace("highlight/styles/base16/tomorrow.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUU1oKBNuCv8rWlUDbHFkWogXJrYVrdP1), "text/css"});
        rtn.emplace("highlight/styles/base16/twilight.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUToQOm3w59e9grF6T0ZEBr1zEYCiKNSePcwQah4GYNRttwzjFpItJ5vhviPPXXWdVEh), "text/css"});
        rtn.emplace("highlight/styles/base16/twilight.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUU1oKBNuCv8raPiOLM4Q1ExjRvjHdtRL), "text/css"});
        rtn.emplace("highlight/styles/base16/unikitty-dark.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV1JpVXIM4mpPSsplj6Zia7ST8TUFvQaKjCp9OGGhprzTnL0i5LwimRHgNPXNM9zjaH4v2xFVD), "text/css"});
        rtn.emplace("highlight/styles/base16/unikitty-dark.min.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8YqqCcyksubNH8qdyXguYFtlmZZY9iwSYne1wT8tKMjNx9UtEcM3TzGvmDN0ldAPG7UtBamv7z1ohP), "text/css"});
        rtn.emplace("highlight/styles/base16/unikitty-light.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg5RsgDTn9lcH9GPl4F9U58nYIzkvl7m1aexCmBAz0Avr1ikw26cSu0f0yfRoRVJkjan4wBeY9D), "text/css"});
        rtn.emplace("highlight/styles/base16/unikitty-light.min.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVLuBY8wrajiK6mXN3z7BVReHIYsn29ZNvgzI1QKiS5rOuFDY4MN4NozuZ5D1AfwJomOFINGQ5mt6lHP), "text/css"});
        rtn.emplace("highlight/styles/base16/vulcan.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTCfNfpoaxpqkzOvUOumxgM31), "text/css"});
        rtn.emplace("highlight/styles/base16/vulcan.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWIAxBw7kALCCGrrxBRsYd), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-10-light.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MyGW7VBM1775bV9gGsTCAdB5SxT6EH40g3Ogjo6cLyOgu45ctnDWHRC6PUkbsoOZU2oldYFQVRwp), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-10-light.min.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPczTajTfpZ2Y8GHiVHh3TPTOaE1JDjJEa7LkIEs02WOpbLhGUHSsB9JKw1oLXoJ8rTEe3BGssPOHf8S9pr), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-10.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWIB3jSb6OGwqamWQp9k8Z), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-10.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg5RsgDTn9lcH9GPl4F9U58nYIzkvl7m1aexCmBAz0Avr1ikw26dUcO2tOCty7uUfAq93rqpjUp), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-95-light.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MyGW7VBM1775bV9gGsTCAdB5SxT6EH40g3Ogjo6cLyOgu45ctnDWHRC6PUkbw2WQMuZZnx7wgk8R), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-95-light.min.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPczTajTfpZ2Y8GHiVHh3TPTOaE1JDjJEa7LkIEs02WOpbLhGUHSsB9JKw1oLY3RMj4gaYpMnaGAlUDdlwJ), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-95.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWIB3jSb6OGwqap1fatsd1), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-95.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg5RsgDTn9lcH9GPl4F9U58nYIzkvl7m1aexCmBAz0Avr1ikw26dUcO2tOCty86ERWyIiH1Kwsd), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-high-contrast-light.css", embedded_file{saucer::stash<>::view(fQKGU5x159P3m1Ah6ZyyIpu9xxpipeFJfPe7uZ3hhYsRxseaVYO3sup5Q7UwQoha5w7sG4vljzEL75m9ePYJzcEp722vdYEWd4Xpd4d), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-high-contrast-light.min.css", embedded_file{saucer::stash<>::view(f1zQIxhLlQBShZJblWCEc97xAqv9YdC7lkXfT29jJnzUzVJnPDzvbrwv7lfDLzhVAsjFVXd6NJdrf2QXn7dHBqHjcLevbgfvUt21ATe8ErU15), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-high-contrast.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89ozqBfmWiugWw7F9lB3mLRBNVZtPMh5QD8Ln9JOyAPmX4Dae527Di2RqRbTt4XzbcLIa3pWRLbbuwDi5IVn), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-high-contrast.min.css", embedded_file{saucer::stash<>::view(f1XjtLeY7kEHn3uAOla2WtIqkhmArnwhH4LSzKePpbJipdsv3YnYnbu7pu0PwwotVyXQdiqoD9xXKM0CWxrDuuDQqRpB22Jwh4phj), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-nt-light.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MyGW7VBM1775bV9gGsTCAdB5SxT6EH40g3Ogjo6cLyOgu45ctnDWHRC6PUkcHTH0Y34GYXmivgln), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-nt-light.min.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPczTajTfpZ2Y8GHiVHh3TPTOaE1JDjJEa7LkIEs02WOpbLhGUHSsB9JKw1oLZfukYkXBQdLu5VwpvL1Ujj), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-nt.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWIB3jSb6OGwqb5eNkpU4R), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-nt.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg5RsgDTn9lcH9GPl4F9U58nYIzkvl7m1aexCmBAz0Avr1ikw26dUcO2tOCty9MAZlDYNzc7xgJ), "text/css"});
        rtn.emplace("highlight/styles/base16/woodland.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUToQOm3w59e9grF6T0ZEBr1zEYCiKNSePcwQah4GYNRttwzjFpIuVBKjJl7iO2gWzbf), "text/css"});
        rtn.emplace("highlight/styles/base16/woodland.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUU1oKBNuCv8xBkHA6cC8s4jpSUaqKoXD), "text/css"});
        rtn.emplace("highlight/styles/base16/xcode-dusk.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MctQwgaIWIBAQwu8Y8co3z7GWk16h), "text/css"});
        rtn.emplace("highlight/styles/base16/xcode-dusk.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg5RsgDTn9lcH9GPl4F9U58nYIzkvl7m1aexCmBAz0Avr1ikw26e02GCnG3el50gYu85LsyIOvL), "text/css"});
        rtn.emplace("highlight/styles/base16/zenburn.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFtRiDjIxE8aIrkjwud46DoyZcuC8a1VRh5), "text/css"});
        rtn.emplace("highlight/styles/base16/zenburn.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XQatGJpsTL51yOr6xD9aV85NLtAxut), "text/css"});
        rtn.emplace("highlight/styles/brown-paper.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVNAvEYAwOY5oVTsI4PyUTUIefGgARSnoBPHM9xVIMztIQNqnM0wnIxrt4p7Nz), "text/css"});
        rtn.emplace("highlight/styles/brown-paper.min.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUToQOm3w59e9grF6T0ZEBr1zEYCiKNSePcwQah4GYNS2iMRAEphgvB8wZb2koEIvVWV), "text/css"});
        rtn.emplace("highlight/styles/brown-papersq.png", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTCftiuPTr7usOTvHzHjUOXyR), "image/png"});
        rtn.emplace("highlight/styles/codepen-embed.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTCnb2uNvbekSRHkjYuiKeA3H), "text/css"});
        rtn.emplace("highlight/styles/codepen-embed.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MdVwxT3Hs7i3bzaRQwa9WIxqLd1ff), "text/css"});
        rtn.emplace("highlight/styles/color-brewer.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLXh6K57B7Mm0XzMAcFFlpl71uOs77OvfD6NfV7hDqzPwGVYYsLZyBvcVmzUwvT), "text/css"});
        rtn.emplace("highlight/styles/color-brewer.min.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr6D0ISFpHpo0xqMhmLSawyCq5EV28sIronFnVpcLwyXEhKbTZo2eJzK6IQ7leczXZUR), "text/css"});
        rtn.emplace("highlight/styles/dark.css", embedded_file{saucer::stash<>::view(f7OPm7vIuBp2CQunSckZbTM7TWMkL8Kp7Ww7R3u1jcdwSvu6LekPTWsLn9bVWOh), "text/css"});
        rtn.emplace("highlight/styles/dark.min.css", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzsIByLsdRRDqFTtopAfSz2ygwQKNpbRNB5LbB937JU52BkLcKdjwlu5L), "text/css"});
        rtn.emplace("highlight/styles/default.css", embedded_file{saucer::stash<>::view(f8OUOpBG2Ne4qHVWvj17c82rpDXNRtNbXBrRpviee6e3Bt3mEo8zLflgy7ZM7a96MUt), "text/css"});
        rtn.emplace("highlight/styles/default.min.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVNAvEYAwOY5oVTsI4PyUTUIefGgARSnoBPHM9xVIN0mWOmeUK5zm5GHI4fMo7), "text/css"});
        rtn.emplace("highlight/styles/devibeans.css", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1rUB7RCLarIP9jvSTrI3Dg4IbJEiAP4b1hm5BW1MsCTozzO5SqmPQFF1nP), "text/css"});
        rtn.emplace("highlight/styles/devibeans.min.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTCv5NFo33dGtvdMmbtr3rMCB), "text/css"});
        rtn.emplace("highlight/styles/docco.css", embedded_file{saucer::stash<>::view(fUWoQiic40oj5L8WEC0J0jDKrtdvLGPz55zyhk7LANYvPT5eDQFdBwwcwvkRXcVn), "text/css"});
        rtn.emplace("highlight/styles/docco.min.css", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1rUB7RCLarIP9jvSTrI3Dg4IbJEiAP4b1hm5BW1MsCXoh3lf0dWtvwm7hj), "text/css"});
        rtn.emplace("highlight/styles/far.css", embedded_file{saucer::stash<>::view(f1n1OjVncnMWz8SHn4XYmJDagVZXVH28VMzXlj1SVsPAlh5LseNphWKvL8HYx9), "text/css"});
        rtn.emplace("highlight/styles/far.min.css", embedded_file{saucer::stash<>::view(f8OUOpBG2Ne4qHVWvj17c82rpDXNRtNbXBrRpviee6e3Bt3mEo8zLrlKctw23HjDVj9), "text/css"});
        rtn.emplace("highlight/styles/felipec.css", embedded_file{saucer::stash<>::view(f8OUOpBG2Ne4qHVWvj17c82rpDXNRtNbXBrRpviee6e3Bt3mEo8zLrr9aKJzkOcKf4N), "text/css"});
        rtn.emplace("highlight/styles/felipec.min.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVNAvEYAwOY5oVTsI4PyUTUIefGgARSnoBPHM9xVIN1hBzCxA2bxxFkwv0bgu3), "text/css"});
        rtn.emplace("highlight/styles/foundation.css", embedded_file{saucer::stash<>::view(f9WyAbPBHunlngqbuiIzAC3zsDdFbI2XIThko3QkMxWyt2kXPYDeS1WerhN9sYn8nvKPZYJ), "text/css"});
        rtn.emplace("highlight/styles/foundation.min.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFtRiDjIxE8cPJG9Ch13CUTIU3Y3c7YSA3n), "text/css"});
        rtn.emplace("highlight/styles/github-dark-dimmed.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XcpiKcggOh5gHnf3FfGEhqny7nixXv), "text/css"});
        rtn.emplace("highlight/styles/github-dark-dimmed.min.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYTmV7mJf0yKc2oFmMLWZADEKbeQzmUa6IZN6Skw9LteWMcyq8kgu0UXAiY7IIklM9UOZlpLUNpOF), "text/css"});
        rtn.emplace("highlight/styles/github-dark.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVNAvEYAwOY5oVTsI4PyUTUIefGgARSnoBPHM9xVIN29yMVs1Ur7VcvVuTy6sN), "text/css"});
        rtn.emplace("highlight/styles/github-dark.min.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUToQOm3w59e9grF6T0ZEBr1zEYCiKNSePcwQah4GYNcgE6XdXh0kUp5IJn6NJ9tdA83), "text/css"});
        rtn.emplace("highlight/styles/github.css", embedded_file{saucer::stash<>::view(f223UEKeDAZNSA3HB4bZGV0h4AXkqlnnID2luecQJOrID3A7K3QOXthXL6IYwcfFvH), "text/css"});
        rtn.emplace("highlight/styles/github.min.css", embedded_file{saucer::stash<>::view(f9WyAbPBHunlngqbuiIzAC3zsDdFbI2XIThko3QkMxWyt2kXPYDeS8E8MFVMUOHWryqtr9f), "text/css"});
        rtn.emplace("highlight/styles/gml.css", embedded_file{saucer::stash<>::view(f1n1OjVncnMWz8SHn4XYmJDagVZXVH28VMzXlj1SVsPAlh5LseNphXgahXI895), "text/css"});
        rtn.emplace("highlight/styles/gml.min.css", embedded_file{saucer::stash<>::view(f8OUOpBG2Ne4qHVWvj17c82rpDXNRtNbXBrRpviee6e3Bt3mEo8zLy5ZkY135o9J7it), "text/css"});
        rtn.emplace("highlight/styles/googlecode.css", embedded_file{saucer::stash<>::view(f9WyAbPBHunlngqbuiIzAC3zsDdFbI2XIThko3QkMxWyt2kXPYDeS8O4a6z5W8i0SVvxwyh), "text/css"});
        rtn.emplace("highlight/styles/googlecode.min.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFtRiDjIxE8cvTfRCrXBRbNw5QHrhz0SaPL), "text/css"});
        rtn.emplace("highlight/styles/gradient-dark.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTDIqwehJGFCRwTeVAfWR50RX), "text/css"});
        rtn.emplace("highlight/styles/gradient-dark.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MfsU7OT9LrVk00WPspZPRk2vVwyKh), "text/css"});
        rtn.emplace("highlight/styles/gradient-light.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFtRiDjIxE8cvqcC2pX4lPNVHkWKDJngMxn), "text/css"});
        rtn.emplace("highlight/styles/gradient-light.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XcuyMX2McGx3wFVN5pddZuYIIp6XVj), "text/css"});
        rtn.emplace("highlight/styles/grayscale.css", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1rUB7RCLarIP9jvSTrI3Dg4IbJEiAP4b1hm5BW1MsHY8jz1HtmV1tENTSl), "text/css"});
        rtn.emplace("highlight/styles/grayscale.min.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTDIqwh1gOnqGG35ZsmKaJT7b), "text/css"});
        rtn.emplace("highlight/styles/hybrid.css", embedded_file{saucer::stash<>::view(f223UEKeDAZNSA3HB4bZGV0h4AXkqlnnID2luecQJOrID3A7K3QOXvFw0zoiY173S7), "text/css"});
        rtn.emplace("highlight/styles/hybrid.min.css", embedded_file{saucer::stash<>::view(f9WyAbPBHunlngqbuiIzAC3zsDdFbI2XIThko3QkMxWyt2kXPYDeSFW3u9cbnsUhhCjbzL1), "text/css"});
        rtn.emplace("highlight/styles/idea.css", embedded_file{saucer::stash<>::view(f7OPm7vIuBp2CQunSckZbTM7TWMkL8Kp7Ww7R3u1jcdwSvu6LekPTxYH75BPSUt), "text/css"});
        rtn.emplace("highlight/styles/idea.min.css", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzsIByLsdRRDqFTtopAfSz2ygwQKNpbRNB5LbB937LV8sZCYFCVKN3ko7), "text/css"});
        rtn.emplace("highlight/styles/intellij-light.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFtRiDjIxE8dxhD7V8d2JdrXbd5CQRekkdP), "text/css"});
        rtn.emplace("highlight/styles/intellij-light.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XhkIqgM068FX7WCAlETAOG57R5AJYB), "text/css"});
        rtn.emplace("highlight/styles/ir-black.css", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzsIByLsdRRDqFTtopAfSz2ygwQKNpbRNB5LbB937LWUAaw8utsP2wwt9), "text/css"});
        rtn.emplace("highlight/styles/ir-black.min.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLXh6K57B7Mm0XzMAcFFlpl71uOs77OvfD6NfV7hDrAl9R0kt5wmfFDiedXYHT9), "text/css"});
        rtn.emplace("highlight/styles/isbl-editor-dark.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr6D0ISFpHpo0xqMhmLSawyCq5EV28sIronFnVpcLxpkaSWE45xKCJL5lvwuP6XN3uDr), "text/css"});
        rtn.emplace("highlight/styles/isbl-editor-dark.min.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV1JpVXIM4mpPSsplj6Zia7ST8TUFvQaKjCp9OGGhpwihKrem483DqiMAJfTwSHyDEKAr2alJz), "text/css"});
        rtn.emplace("highlight/styles/isbl-editor-light.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8Mh3gMXl44uaxOpr5py7khvlBD8gUN), "text/css"});
        rtn.emplace("highlight/styles/isbl-editor-light.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg5RsgDTn9lcH9GPl4F9U58nYIzkvl7m1aexCmBAz0USYw9YMT3FJBf9WbQd9aEu38Vj1pbOoa3), "text/css"});
        rtn.emplace("highlight/styles/kimbie-dark.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVNAvEYAwOY5oVTsI4PyUTUIefGgARSnoBPHM9xVIN3zJ1drVC0W2RhSRudHmd), "text/css"});
        rtn.emplace("highlight/styles/kimbie-dark.min.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUToQOm3w59e9grF6T0ZEBr1zEYCiKNSePcwQah4GYNlFY9MGeTYpb5oQ3Pe7FnGacr5), "text/css"});
        rtn.emplace("highlight/styles/kimbie-light.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLXh6K57B7Mm0XzMAcFFlpl71uOs77OvfD6NfV7hDrET8YmaunaB8cBiEdpDy4Z), "text/css"});
        rtn.emplace("highlight/styles/kimbie-light.min.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr6D0ISFpHpo0xqMhmLSawyCq5EV28sIronFnVpcLy76D0dwl842OgDcHWP0NQFOprEp), "text/css"});
        rtn.emplace("highlight/styles/lightfair.css", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1rUB7RCLarIP9jvSTrI3Dg4IbJEiAP4b1hm5BW1MsPnj0TCsZTYOEjEvrP), "text/css"});
        rtn.emplace("highlight/styles/lightfair.min.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTDvXKeV6appHNeFz51gBfkSB), "text/css"});
        rtn.emplace("highlight/styles/lioshi.css", embedded_file{saucer::stash<>::view(f223UEKeDAZNSA3HB4bZGV0h4AXkqlnnID2luecQJOrID3A7K3QOY11HhfFhXUR8Tb), "text/css"});
        rtn.emplace("highlight/styles/lioshi.min.css", embedded_file{saucer::stash<>::view(f9WyAbPBHunlngqbuiIzAC3zsDdFbI2XIThko3QkMxWyt2kXPYDeSgXN4eQnc2xROy24rEx), "text/css"});
        rtn.emplace("highlight/styles/magula.css", embedded_file{saucer::stash<>::view(f223UEKeDAZNSA3HB4bZGV0h4AXkqlnnID2luecQJOrID3A7K3QOY2RBkFygzyp6x9), "text/css"});
        rtn.emplace("highlight/styles/magula.min.css", embedded_file{saucer::stash<>::view(f9WyAbPBHunlngqbuiIzAC3zsDdFbI2XIThko3QkMxWyt2kXPYDeSnBTgNafq6sMxgpxhj9), "text/css"});
        rtn.emplace("highlight/styles/mono-blue.css", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1rUB7RCLarIP9jvSTrI3Dg4IbJEiAP4b1hm5BW1MsRVBsSBNSBcRgZGGnb), "text/css"});
        rtn.emplace("highlight/styles/mono-blue.min.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTE3VlqwWLM4gbhnBP2uTpGWx), "text/css"});
        rtn.emplace("highlight/styles/monokai-sublime.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUToQOm3w59e9grF6T0ZEBr1zEYCiKNSePcwQah4GYNpaKlrbjuNYnM36B62xoNzbY4h), "text/css"});
        rtn.emplace("highlight/styles/monokai-sublime.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUVoqYUvmvGfMIROH5C8wjpzBdALqe8nL), "text/css"});
        rtn.emplace("highlight/styles/monokai.css", embedded_file{saucer::stash<>::view(f8OUOpBG2Ne4qHVWvj17c82rpDXNRtNbXBrRpviee6e3Bt3mEo8zMYOnU93RgPYE5v1), "text/css"});
        rtn.emplace("highlight/styles/monokai.min.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVNAvEYAwOY5oVTsI4PyUTUIefGgARSnoBPHM9xVIN4udeVqHZzDW2a7asZI2d), "text/css"});
        rtn.emplace("highlight/styles/night-owl.css", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1rUB7RCLarIP9jvSTrI3Dg4IbJEiAP4b1hm5BW1MsT7nv3VmJBMrI3EljH), "text/css"});
        rtn.emplace("highlight/styles/night-owl.min.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTEB7Sivcw5ivTxeLDt0CRaNf), "text/css"});
        rtn.emplace("highlight/styles/nnfx-dark.css", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1rUB7RCLarIP9jvSTrI3Dg4IbJEiAP4b1hm5BW1MsT9obP8VPQwdxh0eiR), "text/css"});
        rtn.emplace("highlight/styles/nnfx-dark.min.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTEBGtFxKt84iuAgcJZPYaOGJ), "text/css"});
        rtn.emplace("highlight/styles/nnfx-light.css", embedded_file{saucer::stash<>::view(f9WyAbPBHunlngqbuiIzAC3zsDdFbI2XIThko3QkMxWyt2kXPYDeSuOWwRnAXX4PlrZiel1), "text/css"});
        rtn.emplace("highlight/styles/nnfx-light.min.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFtRiDjIxE8gYXk9t0SyriqdYTZEQLhrbOd), "text/css"});
        rtn.emplace("highlight/styles/nord.css", embedded_file{saucer::stash<>::view(f7OPm7vIuBp2CQunSckZbTM7TWMkL8Kp7Ww7R3u1jcdwSvu6LekPUOOdzUKo9yN), "text/css"});
        rtn.emplace("highlight/styles/nord.min.css", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzsIByLsdRRDqFTtopAfSz2ygwQKNpbRNB5LbB937NWzgmhZo2qP62WW3), "text/css"});
        rtn.emplace("highlight/styles/obsidian.css", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzsIByLsdRRDqFTtopAfSz2ygwQKNpbRNB5LbB937NugLfOu9kWKaIt9v), "text/css"});
        rtn.emplace("highlight/styles/obsidian.min.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLXh6K57B7Mm0XzMAcFFlpl71uOs77OvfD6NfV7hDrLxuzAjy5B7pR5RV6e2tqF), "text/css"});
        rtn.emplace("highlight/styles/panda-syntax-dark.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8Ml8oJDkDKzwMFPEmYU49diR9qLu1T), "text/css"});
        rtn.emplace("highlight/styles/panda-syntax-dark.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg5RsgDTn9lcH9GPl4F9U58nYIzkvl7m1aexCmBAz0nbGUtvDF7fZZEudPrg0vCCA4KQ0HuqXsR), "text/css"});
        rtn.emplace("highlight/styles/panda-syntax-light.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2XyeNjMkp4hkxrcD2UOC0Jnku29RrLH), "text/css"});
        rtn.emplace("highlight/styles/panda-syntax-light.min.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYTmV7mJf0yKc2oFmMLWZADEKbeQzmUa6IZN6Skw9LvIns7auEgRferVZqknqpKNmv0NfnOncZIpf), "text/css"});
        rtn.emplace("highlight/styles/paraiso-dark.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLXh6K57B7Mm0XzMAcFFlpl71uOs77OvfD6NfV7hDrNqS3t85XXeqoFA4vhaO6l), "text/css"});
        rtn.emplace("highlight/styles/paraiso-dark.min.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr6D0ISFpHpo0xqMhmLSawyCq5EV28sIronFnVpcLyp3UwUv3AR531V0BWmMR0p7mrhb), "text/css"});
        rtn.emplace("highlight/styles/paraiso-light.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTEQSZs3dOsUyityPt7dxG5Bb), "text/css"});
        rtn.emplace("highlight/styles/paraiso-light.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8Ml8oRlXfZ55p3piECImBzxbv3NA4x), "text/css"});
        rtn.emplace("highlight/styles/pojoaque.css", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzsIByLsdRRDqFTtopAfSz2ygwQKNpbRNB5LbB937OKtuT5ATvGS4hVbP), "text/css"});
        rtn.emplace("highlight/styles/pojoaque.jpg", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzsIByLsdRRDqFTtopAfSz2ygwQKNpbRNB5LbB937OKtuT5ATvGS4jQk3), "image/jpeg"});
        rtn.emplace("highlight/styles/pojoaque.min.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLXh6K57B7Mm0XzMAcFFlpl71uOs77OvfD6NfV7hDrNwprLWF1Q3QWl8NPAYxQB), "text/css"});
        rtn.emplace("highlight/styles/purebasic.css", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1rUB7RCLarIP9jvSTrI3Dg4IbJEiAP4b1hm5BW1MsWWjMV9Kcrpq6UlRK7), "text/css"});
        rtn.emplace("highlight/styles/purebasic.min.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAx7y6v7duQ2EGLLXpuz7ViX1sshROYw6A6LjMVmTER4JiyzaTBK4sJW5OIwtyp1), "text/css"});
        rtn.emplace("highlight/styles/qtcreator-dark.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVRE8uCZrYmxVCtU8xiNIN0xsNmbrN7QFtRiDjIxE8i7oApuCqokOWOYaRcsJsIiSB), "text/css"});
        rtn.emplace("highlight/styles/qtcreator-dark.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2Y1GN7rS4AtdSiCTb8XCkzn7wp5xc7H), "text/css"});
        rtn.emplace("highlight/styles/qtcreator-light.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUToQOm3w59e9grF6T0ZEBr1zEYCiKNSePcwQah4GYNyCFAkK545XZFlRezsn3SCI5cx), "text/css"});
        rtn.emplace("highlight/styles/qtcreator-light.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUWTDbUShtEziwYVjYrSXNTeDF5nVko6N), "text/css"});
        rtn.emplace("highlight/styles/rainbow.css", embedded_file{saucer::stash<>::view(f8OUOpBG2Ne4qHVWvj17c82rpDXNRtNbXBrRpviee6e3Bt3mEo8zN2HqOTKElWULcvL), "text/css"});
        rtn.emplace("highlight/styles/rainbow.min.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVNAvEYAwOY5oVTsI4PyUTUIefGgARSnoBPHM9xVIN7Al0qMdGfCmJ5DRpkJvv), "text/css"});
        rtn.emplace("highlight/styles/routeros.css", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzsIByLsdRRDqFTtopAfSz2ygwQKNpbRNB5LbB937P8oZvXS2EwqkDufj), "text/css"});
        rtn.emplace("highlight/styles/routeros.min.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLXh6K57B7Mm0XzMAcFFlpl71uOs77OvfD6NfV7hDrRiq7ySZOZNHUZbcfamFZT), "text/css"});
        rtn.emplace("highlight/styles/school-book.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVNAvEYAwOY5oVTsI4PyUTUIefGgARSnoBPHM9xVIN7dJQISQw5ry4N7Pw8FVr), "text/css"});
        rtn.emplace("highlight/styles/school-book.min.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUToQOm3w59e9grF6T0ZEBr1zEYCiKNSePcwQah4GYO2L6MKWrbh5Q47O9Xp4jUCLcTz), "text/css"});
        rtn.emplace("highlight/styles/shades-of-purple.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr6D0ISFpHpo0xqMhmLSawyCq5EV28sIronFnVpcLzFpmmHXtEP2UdOkMzlVULBzZast), "text/css"});
        rtn.emplace("highlight/styles/shades-of-purple.min.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV1JpVXIM4mpPSsplj6Zia7ST8TUFvQaKjCp9OGGhq3NeFVdqaUbhaLvJsofC5fzcB0njT8wM7), "text/css"});
        rtn.emplace("highlight/styles/srcery.css", embedded_file{saucer::stash<>::view(f223UEKeDAZNSA3HB4bZGV0h4AXkqlnnID2luecQJOrID3A7K3QOYBJiNleqh7VZaN), "text/css"});
        rtn.emplace("highlight/styles/srcery.min.css", embedded_file{saucer::stash<>::view(f9WyAbPBHunlngqbuiIzAC3zsDdFbI2XIThko3QkMxWyt2kXPYDeTSoQZgvCUBZl2pxzWy3), "text/css"});
        rtn.emplace("highlight/styles/stackoverflow-dark.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4qeZuUeIjsinM4Hgn6dRCsYKqMuNYXO5Q8hLvdI2Y680iPPtw2EYUt904Cq8AT2Utgzi9z), "text/css"});
        rtn.emplace("highlight/styles/stackoverflow-dark.min.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYTmV7mJf0yKc2oFmMLWZADEKbeQzmUa6IZN6Skw9LvrrQtWNMYV16MzfeoZ9wbjeMkpyXh3SLAcV), "text/css"});
        rtn.emplace("highlight/styles/stackoverflow-light.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUWnJ4xMwwxdE6RXhAHN1IZjiaLLVosVP), "text/css"});
        rtn.emplace("highlight/styles/stackoverflow-light.min.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MyGW7VBM1775bV9gGsTCAdB5SxT6EH40g3Ogjo6cYwOd3FgT8S4YIwe0WnBHLKi6ep7LXz5v1H2B), "text/css"});
        rtn.emplace("highlight/styles/sunburst.css", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzsIByLsdRRDqFTtopAfSz2ygwQKNpbRNB5LbB937PYLsWZCVaM4L8uEV), "text/css"});
        rtn.emplace("highlight/styles/sunburst.min.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLXh6K57B7Mm0XzMAcFFlpl71uOs77OvfD6NfV7hDrTeYsEypdLsbcO9RqPWZ6Z), "text/css"});
        rtn.emplace("highlight/styles/tokyo-night-dark.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr6D0ISFpHpo0xqMhmLSawyCq5EV28sIronFnVpcLzOvLS9e9W8tYRYgNnqaBdmHgR8N), "text/css"});
        rtn.emplace("highlight/styles/tokyo-night-dark.min.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV1JpVXIM4mpPSsplj6Zia7ST8TUFvQaKjCp9OGGhq44GIbXdrF2Ywpv76Je7RHuN4AKDAHZA3), "text/css"});
        rtn.emplace("highlight/styles/tokyo-night-light.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcxFdhECfLlduVz6Dklcc4ZUb13bs8qeDuDjNERR8MnWumaFpnIijODnD0KfdEL0l0EZqV), "text/css"});
        rtn.emplace("highlight/styles/tokyo-night-light.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg5RsgDTn9lcH9GPl4F9U58nYIzkvl7m1aexCmBAz0ynbIp0uZq6aIwNpKITAw6eBkZ3fBM8bYZ), "text/css"});
        rtn.emplace("highlight/styles/tomorrow-night-blue.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6Au1PYHGYPNRwxn7h2glOqLBFm4EanGbrSNvv0XyEUWx9mHkfpdIfszXv5WduafrwURZBxLrH), "text/css"});
        rtn.emplace("highlight/styles/tomorrow-night-blue.min.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MyGW7VBM1775bV9gGsTCAdB5SxT6EH40g3Ogjo6cZgZfyuRo1GwTNWyhGgqkIcP8bN0kB7tQFStf), "text/css"});
        rtn.emplace("highlight/styles/tomorrow-night-bright.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg5RsgDTn9lcH9GPl4F9U58nYIzkvl7m1aexCmBAz0ynbcWDIgcgeht3HN3hV5526lBF4vNg5SN), "text/css"});
        rtn.emplace("highlight/styles/tomorrow-night-bright.min.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVLuBY8wrajiK6mXN3z7BVReHIYsn29ZNvgzI1QKiVrdzbsmJsfJtQl7zrcx4d35FDy9pIWkAf5Su2S3), "text/css"});
        rtn.emplace("highlight/styles/vs.css", embedded_file{saucer::stash<>::view(fQt4XIqDkpTIgFZJ9KikZeaUdc9ZBOFcb3HNfQ1ZoTLUvPzyDee8CMb45z6J), "text/css"});
        rtn.emplace("highlight/styles/vs.min.css", embedded_file{saucer::stash<>::view(f223UEKeDAZNSA3HB4bZGV0h4AXkqlnnID2luecQJOrID3A7K3QOYFiFUGgWqNMOFn), "text/css"});
        rtn.emplace("highlight/styles/vs2015.css", embedded_file{saucer::stash<>::view(f223UEKeDAZNSA3HB4bZGV0h4AXkqlnnID2luecQJOrID3A7K3QOYFiFoHrSuDPPhT), "text/css"});
        rtn.emplace("highlight/styles/vs2015.min.css", embedded_file{saucer::stash<>::view(f9WyAbPBHunlngqbuiIzAC3zsDdFbI2XIThko3QkMxWyt2kXPYDeTnQ8EdCydhbE9zWMiaR), "text/css"});
        rtn.emplace("highlight/styles/xcode.css", embedded_file{saucer::stash<>::view(fUWoQiic40oj5L8WEC0J0jDKrtdvLGPz55zyhk7LANYvPT5eDQFdJ1UdnimYvGHz), "text/css"});
        rtn.emplace("highlight/styles/xcode.min.css", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1rUB7RCLarIP9jvSTrI3Dg4IbJEiAP4b1hm5BW1MsjhnX0p0ThOwwcav8V), "text/css"});
        rtn.emplace("highlight/styles/xt256.css", embedded_file{saucer::stash<>::view(fUWoQiic40oj5L8WEC0J0jDKrtdvLGPz55zyhk7LANYvPT5eDQFdJ2vrLGOC5RKN), "text/css"});
        rtn.emplace("highlight/styles/xt256.min.css", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1rUB7RCLarIP9jvSTrI3Dg4IbJEiAP4b1hm5BW1MsjoXnhX1DGgEscptw3), "text/css"});
        rtn.emplace("html/card.html", embedded_file{saucer::stash<>::view(fIMvMxLtCtgaCyOWT9Sq2cpZQFAUlr60fpjd781IKV2QwoDk), "text/html"});
        rtn.emplace("html/einstellungen.html", embedded_file{saucer::stash<>::view(fQt4XIqDkpTIgFZJ9KikZeaUdc9ZBOG3PdMTC9xmECkDkS82l8YcpHknBBMq), "text/html"});
        rtn.emplace("html/index.html", embedded_file{saucer::stash<>::view(f1Dqesn4NxFvpVZNG4N54sqKwGMdL3bEomjcPeIDDbCgBnsxvo), "text/html"});
        rtn.emplace("ico/toolbox.ico", embedded_file{saucer::stash<>::view(f1Dqesn4NxFvpVZNG4N54sqKwGMdL3bfGtRIoHuavdKqwZ8lSx), "image/vnd.microsoft.icon"});
        rtn.emplace("ico/toolbox.png", embedded_file{saucer::stash<>::view(f1Dqesn4NxFvpVZNG4N54sqKwGMdL3bfGtRIoHuavdKqwZAhXT), "image/png"});

        return rtn;
    }
} // namespace saucer::embedded
