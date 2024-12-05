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
#include "html/index.html.hpp"
#include "ico/toolbox.png.hpp"

namespace saucer::embedded
{
    inline auto all()
    {
        std::unordered_map<std::string, embedded_file> rtn;

        rtn.emplace("highlight/DIGESTS.md", embedded_file{saucer::stash<>::view(fNgFoiPU0WwvKNGfJGozZgXEpEPj3ZA87oeEJtVomv2ZjkXDACdb4VN6), "text/markdown"});
        rtn.emplace("highlight/es/core.js", embedded_file{saucer::stash<>::view(fNgFoiPU0WwvKNGfJGozZgXEpEPj3ZA87oeEJtVomv3MHRrjwsbWNyYV), "application/javascript"});
        rtn.emplace("highlight/es/core.min.js", embedded_file{saucer::stash<>::view(f1n1OjVncnMWz7siAWJ9NCTPRV14H7ndsoQGmsZKio8F9zMbY1JfDs1eFpT7IJ), "application/javascript"});
        rtn.emplace("highlight/es/highlight.js", embedded_file{saucer::stash<>::view(f7OPm7vIuBp2COXuNRP4hnVR3Y4PeiCygKCTJpJtZ102bFNN2ew9iDsOvQuEpIx), "application/javascript"});
        rtn.emplace("highlight/es/highlight.min.js", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzhBYbgTBOrHu6VXIbHy2eQWWNmyHCYRMnPG0KiKhnROy6pI4nE82qHi7), "application/javascript"});
        rtn.emplace("highlight/es/languages/asciidoc.js", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3j9Gjtbvim6HITK9BzhAUQhr0O9bSI2q5T), "application/javascript"});
        rtn.emplace("highlight/es/languages/asciidoc.min.js", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKwiZcyE8UVUd5Ysr6vWhSQuxxcH4t7awhND7T2B), "application/javascript"});
        rtn.emplace("highlight/es/languages/http.js", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1qkJitbMV4e1vesDUnyBuwvWHiECt1qD080IaIkSODyerUnvsOBgrH40jz), "application/javascript"});
        rtn.emplace("highlight/es/languages/http.min.js", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3j9Gjtbvim6HITK9BzhBAlGJYF0FdQDjqF), "application/javascript"});
        rtn.emplace("highlight/es/languages/json.js", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1qkJitbMV4e1vesDUnyBuwvWHiECt1qD080IaIkSODyerUnvsQlEAhub4t), "application/javascript"});
        rtn.emplace("highlight/es/languages/json.min.js", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3j9Gjtbvim6HITK9BzhBMpCGZmAObsjg1r), "application/javascript"});
        rtn.emplace("highlight/es/languages/lua.js", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzhBYbgTBOrHu6VXIbHy2eQWWNmyHCYRMnPG7p2X1zVdvWA9enjSIiwAV), "application/javascript"});
        rtn.emplace("highlight/es/languages/lua.min.js", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLWr1tqHy9QWq5hnICXIgUsGDpOIdRrhO2bGrGOtF59nj58ESNcytzYRfFYYJkJ), "application/javascript"});
        rtn.emplace("highlight/es/languages/markdown.js", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3j9Gjtbvim6HITK9BzhBeX0Whck6T4lqSp), "application/javascript"});
        rtn.emplace("highlight/es/languages/markdown.min.js", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKwiZcyE8UVUd5Ysr6vWmuSM8toDBfkXEAEVIKnb), "application/javascript"});
        rtn.emplace("highlight/es/languages/shell.js", embedded_file{saucer::stash<>::view(f9WyAbPBHunlndnFRNaGuJBHy4lrjCKXD9JVJ8cfDDbZgX3EjtPpE1iSitCAzWAzsthPcaR), "application/javascript"});
        rtn.emplace("highlight/es/languages/shell.min.js", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LOQH7VccKsbvQH5BxWkMXlW8Z0rfBU796e3), "application/javascript"});
        rtn.emplace("highlight/es/languages/sql.js", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzhBYbgTBOrHu6VXIbHy2eQWWNmyHCYRMnPG7p2X1zVdvWA9epueufToh), "application/javascript"});
        rtn.emplace("highlight/es/languages/sql.min.js", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLWr1tqHy9QWq5hnICXIgUsGDpOIdRrhO2bGrGOtF59nj58ESNnCkvVj6pBVAf5), "application/javascript"});
        rtn.emplace("highlight/es/languages/xml.js", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzhBYbgTBOrHu6VXIbHy2eQWWNmyHCYRMnPG7p2X1zVdvWA9erT8zWC71), "application/javascript"});
        rtn.emplace("highlight/es/languages/xml.min.js", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLWr1tqHy9QWq5hnICXIgUsGDpOIdRrhO2bGrGOtF59nj58ESNuV5njYNS58PiN), "application/javascript"});
        rtn.emplace("highlight/es/package.json", embedded_file{saucer::stash<>::view(f7OPm7vIuBp2COXuNRP4hnVR3Y4PeiCygKCTJpJtZ102bFNQFW7vW1bF8BxESNC), "application/json"});
        rtn.emplace("highlight/highlight.js", embedded_file{saucer::stash<>::view(f6Vk928ltQ1ldGDLsosPtPNK2puP3zGaqrWjVRe3FteHIrddMUeWYxYH1ud), "application/javascript"});
        rtn.emplace("highlight/highlight.min.js", embedded_file{saucer::stash<>::view(fUWoQiic40oj5BM0mn9XQqPniegDw6XaYlPV3ru9Qa8GKDwN4QuRQFN4cD5TJYGp), "application/javascript"});
        rtn.emplace("highlight/languages/asciidoc.js", embedded_file{saucer::stash<>::view(f9WyAbPBHunlndnFRNaGuJBHy4lrjCKXD9JVJ8cfDDbdlfCnDwk5nXOL8PLP35dgAjkTJUB), "application/javascript"});
        rtn.emplace("highlight/languages/asciidoc.min.js", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LOjPq2kSw2Agy40zr5ZReGJ50KwjFQQan91), "application/javascript"});
        rtn.emplace("highlight/languages/http.js", embedded_file{saucer::stash<>::view(f223UEKeDAZNS9OstFSxO2qQXINyLXv0gxXlIFyZqvlCcKixue8coWzcVehOEZuO3f), "application/javascript"});
        rtn.emplace("highlight/languages/http.min.js", embedded_file{saucer::stash<>::view(f9WyAbPBHunlndnFRNaGuJBHy4lrjCKXD9JVJ8cfDDbdlfCnDwk5nXOL95fxVdUWouseDEx), "application/javascript"});
        rtn.emplace("highlight/languages/json.js", embedded_file{saucer::stash<>::view(f223UEKeDAZNS9OstFSxO2qQXINyLXv0gxXlIFyZqvlCcKixue8coWzcVhGvY0kyOZ), "application/javascript"});
        rtn.emplace("highlight/languages/json.min.js", embedded_file{saucer::stash<>::view(f9WyAbPBHunlndnFRNaGuJBHy4lrjCKXD9JVJ8cfDDbdlfCnDwk5nXOL9HjtSf1gxtLA9QZ), "application/javascript"});
        rtn.emplace("highlight/languages/lua.js", embedded_file{saucer::stash<>::view(fUWoQiic40oj5BM0mn9XQqPniegDw6XaYlPV3ru9Qa8NoY8hGV9OpaEeciPjCCjD), "application/javascript"});
        rtn.emplace("highlight/languages/lua.min.js", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1qkJitbMV4e1vesDUnyBuwvWHiECt1qDzQvpdhlyUt4RP3qLtHJJah8kV9), "application/javascript"});
        rtn.emplace("highlight/languages/markdown.js", embedded_file{saucer::stash<>::view(f9WyAbPBHunlndnFRNaGuJBHy4lrjCKXD9JVJ8cfDDbdlfCnDwk5nXOL9ZRhimsGfkXCJrX), "application/javascript"});
        rtn.emplace("highlight/languages/markdown.min.js", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LOjPq2kSw2Agy415J70caSFBmxt0iHileuR), "application/javascript"});
        rtn.emplace("highlight/languages/shell.js", embedded_file{saucer::stash<>::view(f8OUOpBG2Ne4qEoke7rZDHkTZTuzAy3OrNrPHNy82YUu6HZfNtjcGeER1eLsz7Vftpr), "application/javascript"});
        rtn.emplace("highlight/languages/shell.min.js", embedded_file{saucer::stash<>::view(fdM8RmRybyXVMyJLl3NloVCcC3hdqcun8ISXH1beAaBQCo8pFaYJwXsVNwlcUSgy8rZUSUfj), "application/javascript"});
        rtn.emplace("highlight/languages/sql.js", embedded_file{saucer::stash<>::view(fUWoQiic40oj5BM0mn9XQqPniegDw6XaYlPV3ru9Qa8NoY8hGV9OpaEeetcL8kNP), "application/javascript"});
        rtn.emplace("highlight/languages/sql.min.js", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1qkJitbMV4e1vesDUnyBuwvWHiECt1qDzQvpdhlyUt4RPE4CpEalAK5bPv), "application/javascript"});
        rtn.emplace("highlight/languages/xml.js", embedded_file{saucer::stash<>::view(fUWoQiic40oj5BM0mn9XQqPniegDw6XaYlPV3ru9Qa8NoY8hGV9OpaEegS6PzSfj), "application/javascript"});
        rtn.emplace("highlight/languages/xml.min.js", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1qkJitbMV4e1vesDUnyBuwvWHiECt1qDzQvpdhlyUt4RPLMXhSQ1nDiqTD), "application/javascript"});
        rtn.emplace("highlight/package.json", embedded_file{saucer::stash<>::view(f6Vk928ltQ1ldGDLsosPtPNK2puP3zGaqrWjVRe3FteKVipPAINMlibGeys), "application/json"});
        rtn.emplace("highlight/README.md", embedded_file{saucer::stash<>::view(f5jaldojX46WI0n59ziJkuJfr5ubYHiaqGcny2IqVDoarU0frWG3MpA), "text/markdown"});
        rtn.emplace("highlight/styles/1c-light.css", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzhBYbgTBOrHu6VXIbHy2eQWWNmyHCYRqnfK3dpFSTDv8NlzUOUH1LNx5), "text/css"});
        rtn.emplace("highlight/styles/1c-light.min.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLWr1tqHy9QWq5hnICXIgUsGDpOIdRrhQJGRWBJkTpjkd1r9BPaL9PmJu1bfowt), "text/css"});
        rtn.emplace("highlight/styles/a11y-dark.css", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1qkJitbMV4e1vesDUnyBuwvWHiECt1qF014cp2Rbqq7GSvoclni8XeOYHj), "text/css"});
        rtn.emplace("highlight/styles/a11y-dark.min.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvHdNL6TJgTX2evRE2aozKA1T), "text/css"});
        rtn.emplace("highlight/styles/a11y-light.css", embedded_file{saucer::stash<>::view(f9WyAbPBHunlndnFRNaGuJBHy4lrjCKXD9JVJ8cfDDbhw4R6Ik60IBBzzSj4vt4W2KmO6TL), "text/css"});
        rtn.emplace("highlight/styles/a11y-light.min.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LP2xHxgY044WoaN8j3UjSePgavL8FM6qo7v), "text/css"});
        rtn.emplace("highlight/styles/agate.css", embedded_file{saucer::stash<>::view(fUWoQiic40oj5BM0mn9XQqPniegDw6XaYlPV3ru9Qa8bACNOPmO1dsd8YZ8rYvhb), "text/css"});
        rtn.emplace("highlight/styles/agate.min.css", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1qkJitbMV4e1vesDUnyBuwvWHiECt1qF014cp2RbqqT4hwxPFLp5mCUk8x), "text/css"});
        rtn.emplace("highlight/styles/an-old-hope.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVMyJLl3NloVCcC3hdqcun8ISXH1beAaBhPmJu1OKnDAy1wNVhzkkRU6E1jBad), "text/css"});
        rtn.emplace("highlight/styles/an-old-hope.min.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUTnTHBdJqGhHjeP0zhwZ9dXyDrkeXYcaNQCoARgOGoi0W69qNErvneNEgKfsmTQru55), "text/css"});
        rtn.emplace("highlight/styles/androidstudio.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvHfEovkD7PfFwC8JhEkvhk9L), "text/css"});
        rtn.emplace("highlight/styles/androidstudio.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9V3w97UBhznGKAjkrNm5MbwHsxUpv), "text/css"});
        rtn.emplace("highlight/styles/arduino-light.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvHfMMuAelXU92A4q4LzBIffX), "text/css"});
        rtn.emplace("highlight/styles/arduino-light.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9V4VX3RXCFcE7vkWC3uA2zOmNCLEh), "text/css"});
        rtn.emplace("highlight/styles/arta.css", embedded_file{saucer::stash<>::view(f7OPm7vIuBp2COXuNRP4hnVR3Y4PeiCygKCTJpJtZ10902zqteIPaImwQ8jFyi3), "text/css"});
        rtn.emplace("highlight/styles/arta.min.css", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzhBYbgTBOrHu6VXIbHy2eQWWNmyHCYRqnfK3dpFSmZFGqiwSS0fzTnal), "text/css"});
        rtn.emplace("highlight/styles/ascetic.css", embedded_file{saucer::stash<>::view(f8OUOpBG2Ne4qEoke7rZDHkTZTuzAy3OrNrPHNy82YUxls5LE0IlAnFEhWVBXdXeWsl), "text/css"});
        rtn.emplace("highlight/styles/ascetic.min.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVMyJLl3NloVCcC3hdqcun8ISXH1beAaBhPmJu1OKnDBXmtDUiqc89Uj39Minb), "text/css"});
        rtn.emplace("highlight/styles/atom-one-dark-reasonable.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8XSIn8G6HEWXCCEtYyn2LNnUCnuZOwuzwUVgsAFxJhLLwh8HsB0yX5A3rz2b7Iwat6cUooEHPuw5Ip), "text/css"});
        rtn.emplace("highlight/styles/atom-one-dark-reasonable.min.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89iS8L7J7jQVD2naFD7akSSR03pLkVHp6nMDEC3Grjhrotso7IN3x5dZGJdQyndrigSthGBsktCskHbK6xFr), "text/css"});
        rtn.emplace("highlight/styles/atom-one-dark.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvHfQDtz0F3rnvPt9Axn9G42t), "text/css"});
        rtn.emplace("highlight/styles/atom-one-dark.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9V4nbVYTP6WqyJo5zPUQCHJKywl07), "text/css"});
        rtn.emplace("highlight/styles/atom-one-light.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LP2xHxgY044Wx2HP9t0ByA97kDhXeKDLFCd), "text/css"});
        rtn.emplace("highlight/styles/atom-one-light.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPEJoosILPexejH8Mwzx2g3u3SYDUX5), "text/css"});
        rtn.emplace("highlight/styles/base16/3024.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVMyJLl3NloVCcC3hdqcun8ISXH1beAaBhPmJu1OKnDbtPVbqRecRffuLZ0HH1), "text/css"});
        rtn.emplace("highlight/styles/base16/3024.min.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUTnTHBdJqGhHjeP0zhwZ9dXyDrkeXYcaNQCoARgOGok2kOwLGUxKyQBLC7d7PYYCHSd), "text/css"});
        rtn.emplace("highlight/styles/base16/apathy.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvHmdStgjELBUSIl8KiuyWxz1), "text/css"});
        rtn.emplace("highlight/styles/base16/apathy.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyNjsKQM8J9sQt5jxDYId), "text/css"});
        rtn.emplace("highlight/styles/base16/apprentice.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyNjsQSU2Ol730YGmEI4Z), "text/css"});
        rtn.emplace("highlight/styles/base16/apprentice.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg4Df9nKezyGVcrgQ2mzv0d6TXbBhPFh7e3TqQBpf8weElSqNtvFnx5LJEbsyW4znJUJGU6j9Ep), "text/css"});
        rtn.emplace("highlight/styles/base16/ashes.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLWr1tqHy9QWq5hnICXIgUsGDpOIdRrhQJGRWBJkTrECSnKWGYBz93DapTVTz5X), "text/css"});
        rtn.emplace("highlight/styles/base16/ashes.min.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr2Gsy2LvowjEUpI6nRp9nIGfFwdOYxKCiCt98J2DRW7Layto7qFUMMVjcoROMpkycuh), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-cave-light.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVG8ras6Tv9yL4MXVQR0TgIGKis5aB1HLlVyr1eLsvWxSFRS2YhZMeS734mXvLZWzK7fhEIHrR7n3gIN), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-cave-light.min.css", embedded_file{saucer::stash<>::view(f1MJy0Jkn1m1Rg7YARCAxvZQrrYjeoBLjpVPUFo1o1Bb23nicblVdtdKr6O5Ly6YvlQO19A9zXk2J7vhyUK19jzwt5Y5y8To3), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-cave.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW0KQOuC7FAmIhiU3KWbjSYBQlXiVWsYl), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-cave.min.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MdJ57KMpdqRPicTvOPRCvagfqm5fOvOgk8dvgCaA6q9t1gI1BAuRbYIsuabfNBDUJ2uCqVtYEFVb), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-dune-light.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVG8ras6Tv9yL4MXVQR0TgIGKis5aB1HLlVyr1eLsvWxSFRS2YhZMeS734mXvLgvd2QqcV4emyI7JQEF), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-dune-light.min.css", embedded_file{saucer::stash<>::view(f1MJy0Jkn1m1Rg7YARCAxvZQrrYjeoBLjpVPUFo1o1Bb23nicblVdtdKr6O5Ly6YvlQO19A9zYIiTzqYkMtZEfAf5jqYHkhzX), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-dune.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW0KQOuC7FAmIhiU3KWbjSYHAX7hkG4sF), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-dune.min.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MdJ57KMpdqRPicTvOPRCvagfqm5fOvOgk8dvgCaA6q9t1gI1BAuRbYIsuabfNc7NX1sSqjuR54ZX), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-estuary-light.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89iS8L7J7jQVD2naFD7akSSR03pLkVHp6nMDEC3GrjvTklYtXtjBMhwDZ9U4MAqx0xdznmv8dfz5lej05BVD), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-estuary-light.min.css", embedded_file{saucer::stash<>::view(f1XjtLeY7kEHn3PUNmKTpD03EMKgXUz5My2fLWonN4XpoxCE7VRhZYqhmggSMxLOfdcyiRzoEyv0Frqax2ICenvTmBw0nzk4MlYhP), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-estuary.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYThQPwRhJHsqAaTf9XWJfObSjyjYJEGo3ZONES8rJswA8xz6IguPIJGXdSEg3j37Q4MQ1wGBgsc7), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-estuary.min.css", embedded_file{saucer::stash<>::view(f1CGTDaSS4GQFt4ebIFOlY1B9014Ll9VyYdPRZHL3NVHdsC3GwocMnY5UdlLmZHu1X256hkS4o1N6YwhAEiCkSgNLFDz1), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-forest-light.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPbPDdzLaGKSs1A4PxqhI230j3pfavx3AqdllVyr0Q8akgWBVwXhvKKOb5gdnvsOpMbPxdSVrmtOGqJCysV), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-forest-light.min.css", embedded_file{saucer::stash<>::view(fNBb8dMnLMpmCw05l3zTM2QwD9qvWCr7z2aAXcSQPnqkjKslLf6C0ClPpzcq3iPpjvOOKLGWgzGLFxiBqzKg32RSAYzkLieMbgZ), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-forest.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg4Df9nKezyGVcrgQ2mzv0d6TXbBhPFh7e3TqQBpf8weElSqNtvFoRunnl2aLFIBCjRMeN1zWJH), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-forest.min.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVG8ras6Tv9yL4MXVQR0TgIGKis5aB1HLlVyr1eLsvWxSFRS2YhZMeS734mXvLuUahBTE38flVaFBYhf), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-heath-light.css", embedded_file{saucer::stash<>::view(f1CGTDaSS4GQFt4ebIFOlY1B9014Ll9VyYdPRZHL3NVHdsC3GwocMnY5UdlLmZHu1X256hkS4pMofE5OmM1GhrCxEAP5f), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-heath-light.min.css", embedded_file{saucer::stash<>::view(f5cARlJZCRKHyHvB56IHHRiIwP9QWVCrlEfhEvGZSWtsuVhIFPwAejiQ7GNS6iB6EVoxAjpxGI4IF78p8FvLGsai2u97Se4GTD), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-heath.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV11N2r7QOhAmLWNLo55J8O079acBxsexUWoKvgaFI9ML0q21ueVREVg5kkdnhuvQmpTz1Ipvv), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-heath.min.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8XSIn8G6HEWXCCEtYyn2LNnUCnuZOwuzwUVgsAFxJkFMpCwcOs933z3dyjf9Wy35krMzt1haJL1ywF), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-lakeside-light.css", embedded_file{saucer::stash<>::view(f1MJy0Jkn1m1Rg7YARCAxvZQrrYjeoBLjpVPUFo1o1Bb23nicblVdtdKr6O5Ly6YvlQO19A9zcPZILPaVhzeG0HYuQOlohSL5), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-lakeside-light.min.css", embedded_file{saucer::stash<>::view(f6NJUXPQtyszSY5FSBYZ9RgDLIDPeJwEApv0itVjrGlhyOQUIzqNuptcn2FJ8n2LrvcwhXbDS8OUrkFlhyuqCxPyfLerbihZ3zkkUt), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-lakeside.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MdJ57KMpdqRPicTvOPRCvagfqm5fOvOgk8dvgCaA6q9t1gI1BAuRbYIsuabfQno4BlHRT41ww8Xb), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-lakeside.min.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPbPDdzLaGKSs1A4PxqhI230j3pfavx3AqdllVyr0Q8akgWBVwXhvKKOb5gdnw3cN3cGqk0F9GXsRhX3dUx), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-plateau-light.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89iS8L7J7jQVD2naFD7akSSR03pLkVHp6nMDEC3GrjvTklYtXtjBMhwDZ9U4MCERNis3r07iPMdZP4ebXdbP), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-plateau-light.min.css", embedded_file{saucer::stash<>::view(f1XjtLeY7kEHn3PUNmKTpD03EMKgXUz5My2fLWonN4XpoxCE7VRhZYqhmggSMxLOfdcyiRzoF5NnAMmVzkvEMJuI1I2TvLsTJTTQB), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-plateau.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYThQPwRhJHsqAaTf9XWJfObSjyjYJEGo3ZONES8rJswA8xz6IguPIJGXdSEg3k7Quhq5GiCSfL8t), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-plateau.min.css", embedded_file{saucer::stash<>::view(f1CGTDaSS4GQFt4ebIFOlY1B9014Ll9VyYdPRZHL3NVHdsC3GwocMnY5UdlLmZHu1X256hkS4t2GP0U1POywnoaDEL1O7), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-savanna-light.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89iS8L7J7jQVD2naFD7akSSR03pLkVHp6nMDEC3GrjvTklYtXtjBMhwDZ9U4MCbTyTf8BJVw4lSkohPT88LD), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-savanna-light.min.css", embedded_file{saucer::stash<>::view(f1XjtLeY7kEHn3PUNmKTpD03EMKgXUz5My2fLWonN4XpoxCE7VRhZYqhmggSMxLOfdcyiRzoF77oce3rHvcGCveL9YX1dzKHQvQ3P), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-savanna.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYThQPwRhJHsqAaTf9XWJfObSjyjYJEGo3ZONES8rJswA8xz6IguPIJGXdSEg3kPJ4a6EkCH31ty7), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-savanna.min.css", embedded_file{saucer::stash<>::view(f1CGTDaSS4GQFt4ebIFOlY1B9014Ll9VyYdPRZHL3NVHdsC3GwocMnY5UdlLmZHu1X256hkS4uO3cOOTwd4IWE1djBZP1), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-seaside-light.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89iS8L7J7jQVD2naFD7akSSR03pLkVHp6nMDEC3GrjvTklYtXtjBMhwDZ9U4MCbbMsjYzctEYvMw1FDDTEiB), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-seaside-light.min.css", embedded_file{saucer::stash<>::view(f1XjtLeY7kEHn3PUNmKTpD03EMKgXUz5My2fLWonN4XpoxCE7VRhZYqhmggSMxLOfdcyiRzoF78NHiHVtUThErA3869tcj6Cskn9H), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-seaside.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYThQPwRhJHsqAaTf9XWJfObSjyjYJEGo3ZONES8rJswA8xz6IguPIJGXdSEg3kPOoAJz6VUcG85z), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-seaside.min.css", embedded_file{saucer::stash<>::view(f1CGTDaSS4GQFt4ebIFOlY1B9014Ll9VyYdPRZHL3NVHdsC3GwocMnY5UdlLmZHu1X256hkS4uOUVQMspuvjEVtvxS4MV), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-sulphurpool-light.css", embedded_file{saucer::stash<>::view(f1XjtLeY7kEHn3PUNmKTpD03EMKgXUz5My2fLWonN4XpoxCE7VRhZYqhmggSMxLOfdcyiRzoF7AfCtYHJn7V4B09VFV2IeJG2JO7P), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-sulphurpool-light.min.css", embedded_file{saucer::stash<>::view(f7EqLhcRLMrUY7RiRJI2J5yK88ad34otEv9iTn8gIbPgW9xsf9ei6QSOmTtTLob7BDpl0r8eBASzhVrrGuFv6gMV1tCphHRhGIGh3hIfUB), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-sulphurpool.css", embedded_file{saucer::stash<>::view(f1CGTDaSS4GQFt4ebIFOlY1B9014Ll9VyYdPRZHL3NVHdsC3GwocMnY5UdlLmZHu1X256hkS4uQGaws64jWoBro4H81Ct), "text/css"});
        rtn.emplace("highlight/styles/base16/atelier-sulphurpool.min.css", embedded_file{saucer::stash<>::view(f5cARlJZCRKHyHvB56IHHRiIwP9QWVCrlEfhEvGZSWtsuVhIFPwAejiQ7GNS6iB6EVoxAjpxGflnPOXof1pNmkxTfRsIurIVe7), "text/css"});
        rtn.emplace("highlight/styles/base16/atlas.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLWr1tqHy9QWq5hnICXIgUsGDpOIdRrhQJGRWBJkTrECSnKWGYBz98ckoUnRPL1), "text/css"});
        rtn.emplace("highlight/styles/base16/atlas.min.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr2Gsy2LvowjEUpI6nRp9nIGfFwdOYxKCiCt98J2DRW7Layto7qFUlhnOmpbyyYKTZid), "text/css"});
        rtn.emplace("highlight/styles/base16/bespin.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvHmdStgjELBVrB5x621ClDu7), "text/css"});
        rtn.emplace("highlight/styles/base16/bespin.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyNqRcMxOJbGAErwJ0591), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-bathory.css", embedded_file{saucer::stash<>::view(f1CGTDaSS4GQFt4ebIFOlY1B9014Ll9VyYdPRZHL3NVHdsC3GwocMnY5UdlLmZI3kmQCq7m1d0WQeUCdeUjZ9tFrUyYHj), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-bathory.min.css", embedded_file{saucer::stash<>::view(f5cARlJZCRKHyHvB56IHHRiIwP9QWVCrlEfhEvGZSWtsuVhIFPwAejiQ7GNS6iBpqd6oP28ZB1QstSo8h9WkQ6IsHe8QzLeA1T), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-burzum.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVG8ras6Tv9yL4MXVQR0TgIGKis5aB1HLlVyr1eLsvWxSFRS2YhbikbLVzwcAtpRlaNPDVG3lIpkAu1b), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-burzum.min.css", embedded_file{saucer::stash<>::view(f1MJy0Jkn1m1Rg7YARCAxvZQrrYjeoBLjpVPUFo1o1Bb23nicblVdtdKr6O5Ly6jyhNRhqLRtSvMyttkEc7S1YPhMaojtSVQx), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-dark-funeral.css", embedded_file{saucer::stash<>::view(fNBb8dMnLMpmCw05l3zTM2QwD9qvWCr7z2aAXcSQPnqkjKslLf6C0ClPpzcq3iSs5JU87MpNFVv0f10nt0hTsRN1N4Elps8cX8l), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-dark-funeral.min.css", embedded_file{saucer::stash<>::view(f1khg4GZgTGpTZi0ae1wgPBDaqSFGjFELXDUdBPptqebuE2ONWqy5Qkb07Et3pUWvuSCR8EhhCGbL1G7A6KwrXbiXjBdE69F60Yfn9ppb), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-gorgoroth.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89iS8L7J7jQVD2naFD7akSSR03pLkVHp6nMDEC3GrjvTklYtXtjE2af2Ll4E1K5AtR6MrG7V11TnnJo7O7dr), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-gorgoroth.min.css", embedded_file{saucer::stash<>::view(f1XjtLeY7kEHn3PUNmKTpD03EMKgXUz5My2fLWonN4XpoxCE7VRhZYqhmggSMxLbDJwSPWQG803nOjMZ7b8Sifb7BBB1ShcHNmezz), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-immortal.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPbPDdzLaGKSs1A4PxqhI230j3pfavx3AqdllVyr0Q8akgWBVwXiZV9wD1E6Ij49u3Al1ZzuhwlSQ8Hdv0t), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-immortal.min.css", embedded_file{saucer::stash<>::view(fNBb8dMnLMpmCw05l3zTM2QwD9qvWCr7z2aAXcSQPnqkjKslLf6C0ClPpzcq3iSs5JU87MpNFVv0f1AKK5aF6xRhit67mldFms7), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-khold.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8XSIn8G6HEWXCCEtYyn2LNnUCnuZOwuzwUVgsAFxJkFMpCwcOs9cRkpE2tMo6jsg2VsKG3RtllZcqB), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-khold.min.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89iS8L7J7jQVD2naFD7akSSR03pLkVHp6nMDEC3GrjvTklYtXtjE2af2Ll4E1K5AtR6TSayE5YlR5jxRltfH), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-marduk.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVG8ras6Tv9yL4MXVQR0TgIGKis5aB1HLlVyr1eLsvWxSFRS2YhbikbLVzwcAtpRlaNfCfoSFAiaMDkB), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-marduk.min.css", embedded_file{saucer::stash<>::view(f1MJy0Jkn1m1Rg7YARCAxvZQrrYjeoBLjpVPUFo1o1Bb23nicblVdtdKr6O5Ly6jyhNRhqLRtSvMytuxBMrDhlT26fFg5b7HH), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-mayhem.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVG8ras6Tv9yL4MXVQR0TgIGKis5aB1HLlVyr1eLsvWxSFRS2YhbikbLVzwcAtpRlaNfCgPnUXi43Rfn), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-mayhem.min.css", embedded_file{saucer::stash<>::view(f1MJy0Jkn1m1Rg7YARCAxvZQrrYjeoBLjpVPUFo1o1Bb23nicblVdtdKr6O5Ly6jyhNRhqLRtSvMytuxBPgHvra2ZnYXa9MLj), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-nile.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MdJ57KMpdqRPicTvOPRCvagfqm5fOvOgk8dvgCaA6q9t1gI1BB30uO1wpBosudsk8gxe30VyWPZr), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-nile.min.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPbPDdzLaGKSs1A4PxqhI230j3pfavx3AqdllVyr0Q8akgWBVwXiZV9wD1E6Ij49u3An1xorPEjV5Y6p2jz), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-venom.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8XSIn8G6HEWXCCEtYyn2LNnUCnuZOwuzwUVgsAFxJkFMpCwcOs9cRkpE2tMo6jsg2VwDlZDk8bttzv), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal-venom.min.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89iS8L7J7jQVD2naFD7akSSR03pLkVHp6nMDEC3GrjvTklYtXtjE2af2Ll4E1K5AtR6lip1rVW0HHrNVB1CF), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPGZSJQBRPNKTJabqWiRT8U2Nz0SNmt), "text/css"});
        rtn.emplace("highlight/styles/base16/black-metal.min.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYThQPwRhJHsqAaTf9XWJfObSjyjYJEGo3ZONES8rJswA8xz6IguRMz7kyGGuOvJLUY9tSeazgvy7), "text/css"});
        rtn.emplace("highlight/styles/base16/brewer.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvHmdStgjELBVvlcRRWs8ZNC7), "text/css"});
        rtn.emplace("highlight/styles/base16/brewer.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyNqn8GCYA7Q9Ci0tOAJ1), "text/css"});
        rtn.emplace("highlight/styles/base16/bright.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvHmdStgjELBVvlxOvi6bW8Pr), "text/css"});
        rtn.emplace("highlight/styles/base16/bright.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyNqn9qSjo5gVoyGo405z), "text/css"});
        rtn.emplace("highlight/styles/base16/brogrammer.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyNqnCGCCKCnoxtwIYhRj), "text/css"});
        rtn.emplace("highlight/styles/base16/brogrammer.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg4Df9nKezyGVcrgQ2mzv0d6TXbBhPFh7e3TqQBpf8weElSqNtvGKNEAWfBXdZ8j4FzDhTNAgfT), "text/css"});
        rtn.emplace("highlight/styles/base16/brush-trees-dark.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MdJ57KMpdqRPicTvOPRCvagfqm5fOvOgk8dvgCaA6q9t1gI1BB3DvnqeioRH8QTs0QsKLg4OMTuV), "text/css"});
        rtn.emplace("highlight/styles/base16/brush-trees-dark.min.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPbPDdzLaGKSs1A4PxqhI230j3pfavx3AqdllVyr0Q8akgWBVwXiaUDE69Rep3h07LVdYNBEI3kiNneSzoZ), "text/css"});
        rtn.emplace("highlight/styles/base16/brush-trees.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPGZSJQBRPNKTzIfvZR7M4jv9JwweRP), "text/css"});
        rtn.emplace("highlight/styles/base16/brush-trees.min.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYThQPwRhJHsqAaTf9XWJfObSjyjYJEGo3ZONES8rJswA8xz6IguRQ8fcQKXWlG5RZqVOTp77pamB), "text/css"});
        rtn.emplace("highlight/styles/base16/chalk.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLWr1tqHy9QWq5hnICXIgUsGDpOIdRrhQJGRWBJkTrECSnKWGYBzq3stvrmauIt), "text/css"});
        rtn.emplace("highlight/styles/base16/chalk.min.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr2Gsy2LvowjEUpI6nRp9nIGfFwdOYxKCiCt98J2DRW7Layto7qIk05hw3FRQogmHE27), "text/css"});
        rtn.emplace("highlight/styles/base16/circus.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvHmdStgjELBXLLTg6F7hJ0Z1), "text/css"});
        rtn.emplace("highlight/styles/base16/circus.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyNxPiFO1lBaRaIwZWgcd), "text/css"});
        rtn.emplace("highlight/styles/base16/classic-dark.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW0KQOuC7FAmMQ2Q6DoRRUniT39sz8HND), "text/css"});
        rtn.emplace("highlight/styles/base16/classic-dark.min.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MdJ57KMpdqRPicTvOPRCvagfqm5fOvOgk8dvgCaA6q9t1gI1BBBrO1RRBmx2Y8Q3MAzOPxk2AOBP), "text/css"});
        rtn.emplace("highlight/styles/base16/classic-light.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV11N2r7QOhAmLWNLo55J8O079acBxsexUWoKvgaFI9ML0q21ueVgZVzlh2HJXE87lJaQPCH7D), "text/css"});
        rtn.emplace("highlight/styles/base16/classic-light.min.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8XSIn8G6HEWXCCEtYyn2LNnUCnuZOwuzwUVgsAFxJkFMpCwcOsACyRBxIGg7mkIHnIGo0BcstqVH9P), "text/css"});
        rtn.emplace("highlight/styles/base16/codeschool.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyNxZaqwxmZxPCvDoNF4t), "text/css"});
        rtn.emplace("highlight/styles/base16/codeschool.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg4Df9nKezyGVcrgQ2mzv0d6TXbBhPFh7e3TqQBpf8weElSqNtvGqA6rjSrebm9a7Hw7bP11r87), "text/css"});
        rtn.emplace("highlight/styles/base16/colors.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvHmdStgjELBXNSq56nLRqMMN), "text/css"});
        rtn.emplace("highlight/styles/base16/colors.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyNxZe5Z0rTxDLRAqNy43), "text/css"});
        rtn.emplace("highlight/styles/base16/cupcake.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LP2xHxgY044XQoxJwQlDTdxgzH8Uv0u7G6t), "text/css"});
        rtn.emplace("highlight/styles/base16/cupcake.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPGZSJQBRPNKweSp8D51SAc9jqrgJG7), "text/css"});
        rtn.emplace("highlight/styles/base16/cupertino.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr2Gsy2LvowjEUpI6nRp9nIGfFwdOYxKCiCt98J2DRW7Layto7qIpFxr4fyAhz9B6JbH), "text/css"});
        rtn.emplace("highlight/styles/base16/cupertino.min.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV11N2r7QOhAmLWNLo55J8O079acBxsexUWoKvgaFI9ML0q21ueVgqbkwpqrTMo2yCcPsyWDrf), "text/css"});
        rtn.emplace("highlight/styles/base16/danqing.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LP2xHxgY044XQoxJwQlDTjX7WBkMxgQocol), "text/css"});
        rtn.emplace("highlight/styles/base16/danqing.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPGZSJQBRPNLMlsiHP2cvEZfkZSCKXb), "text/css"});
        rtn.emplace("highlight/styles/base16/darcula.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LP2xHxgY044XQoxJwQlDTjX8uuCcTxbx6jT), "text/css"});
        rtn.emplace("highlight/styles/base16/darcula.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPGZSJQBRPNLMlzGp1pXC1f7NvMLsiR), "text/css"});
        rtn.emplace("highlight/styles/base16/dark-violet.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPGZSJQBRPNLMlzJveYA5Jpgct3Ll2J), "text/css"});
        rtn.emplace("highlight/styles/base16/dark-violet.min.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYThQPwRhJHsqAaTf9XWJfObSjyjYJEGo3ZONES8rJswA8xz6IguVYyqiARaN1NxK2lpHQWfKghzn), "text/css"});
        rtn.emplace("highlight/styles/base16/darkmoss.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUTnTHBdJqGhHjeP0zhwZ9dXyDrkeXYcaNQCoARgOGok2kOwLGUxem0qrnD2vfgDDrFL), "text/css"});
        rtn.emplace("highlight/styles/base16/darkmoss.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW0KQOuC7FAmOE29Chns3qVNPPQtur7Dv), "text/css"});
        rtn.emplace("highlight/styles/base16/darktooth.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr2Gsy2LvowjEUpI6nRp9nIGfFwdOYxKCiCt98J2DRW7Layto7qKMFWI9fimxq3FWkdv), "text/css"});
        rtn.emplace("highlight/styles/base16/darktooth.min.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV11N2r7QOhAmLWNLo55J8O079acBxsexUWoKvgaFI9ML0q21ueVo1ws0eVC1moFTK1j0lY9mF), "text/css"});
        rtn.emplace("highlight/styles/base16/decaf.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLWr1tqHy9QWq5hnICXIgUsGDpOIdRrhQJGRWBJkTrECSnKWGYC0BmddMZHq5YJ), "text/css"});
        rtn.emplace("highlight/styles/base16/decaf.min.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr2Gsy2LvowjEUpI6nRp9nIGfFwdOYxKCiCt98J2DRW7Layto7qKNpsDOMJcjAmGME3n), "text/css"});
        rtn.emplace("highlight/styles/base16/default-dark.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW0KQOuC7FAmOFq9RUcMcmIucyaSCnfGt), "text/css"});
        rtn.emplace("highlight/styles/base16/default-dark.min.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MdJ57KMpdqRPicTvOPRCvagfqm5fOvOgk8dvgCaA6q9t1gI1BBKSuLJ5nXXKSe2BeBtnOwtyhru7), "text/css"});
        rtn.emplace("highlight/styles/base16/default-light.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV11N2r7QOhAmLWNLo55J8O079acBxsexUWoKvgaFI9ML0q21ueVo9PKzWQPQ7UwKkRHqq4x0d), "text/css"});
        rtn.emplace("highlight/styles/base16/default-light.min.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8XSIn8G6HEWXCCEtYyn2LNnUCnuZOwuzwUVgsAFxJkFMpCwcOsAmVMdypwYTchcpFWeYtLRPxYjzl5), "text/css"});
        rtn.emplace("highlight/styles/base16/dirtysea.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUTnTHBdJqGhHjeP0zhwZ9dXyDrkeXYcaNQCoARgOGok2kOwLGUxemnCcudrkj1EfZoJ), "text/css"});
        rtn.emplace("highlight/styles/base16/dirtysea.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW0KQOuC7FAmOHgp9LOxqDqq32qGvPH5n), "text/css"});
        rtn.emplace("highlight/styles/base16/dracula.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LP2xHxgY044XQoxJwQlDTjvvekdropiwN2B), "text/css"});
        rtn.emplace("highlight/styles/base16/dracula.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPGZSJQBRPNLOeBjZF4zfIuPesn5CRH), "text/css"});
        rtn.emplace("highlight/styles/base16/edge-dark.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr2Gsy2LvowjEUpI6nRp9nIGfFwdOYxKCiCt98J2DRW7Layto7qM2TlZGT2uJTYSU8Sx), "text/css"});
        rtn.emplace("highlight/styles/base16/edge-dark.min.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV11N2r7QOhAmLWNLo55J8O079acBxsexUWoKvgaFI9ML0q21ueVvuaqQVmPgojBWmx9Lxf3SN), "text/css"});
        rtn.emplace("highlight/styles/base16/edge-light.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyOB0EuPc2mWKgnfbRUp9), "text/css"});
        rtn.emplace("highlight/styles/base16/edge-light.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg4Df9nKezyGVcrgQ2mzv0d6TXbBhPFh7e3TqQBpf8weElSqNtvHr7g8TTRFb0tH1tUepVF7hD9), "text/css"});
        rtn.emplace("highlight/styles/base16/eighties.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUTnTHBdJqGhHjeP0zhwZ9dXyDrkeXYcaNQCoARgOGok2kOwLGUxfBk97bHXKqUMXa5L), "text/css"});
        rtn.emplace("highlight/styles/base16/eighties.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW0KQOuC7FAmQAf7qgJGbVAMbfraZO4Zv), "text/css"});
        rtn.emplace("highlight/styles/base16/embers.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvHmdStgjELBaIF8SaZcly4YN), "text/css"});
        rtn.emplace("highlight/styles/base16/embers.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyOBFAFlr8LqlBaPGL8q3), "text/css"});
        rtn.emplace("highlight/styles/base16/equilibrium-dark.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MdJ57KMpdqRPicTvOPRCvagfqm5fOvOgk8dvgCaA6q9t1gI1BBTjDl3DXfyY5PUMgxvlmTwqpRgp), "text/css"});
        rtn.emplace("highlight/styles/base16/equilibrium-dark.min.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPbPDdzLaGKSs1A4PxqhI230j3pfavx3AqdllVyr0Q8akgWBVwXkakCOcARFXx1nThdbkayikmwZnO3p2nr), "text/css"});
        rtn.emplace("highlight/styles/base16/equilibrium-gray-dark.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89iS8L7J7jQVD2naFD7akSSR03pLkVHp6nMDEC3GrjvTklYtXtjMNilBdb6WCBjQIeBcyKdeuIIxHbEJDFpL), "text/css"});
        rtn.emplace("highlight/styles/base16/equilibrium-gray-dark.min.css", embedded_file{saucer::stash<>::view(f1XjtLeY7kEHn3PUNmKTpD03EMKgXUz5My2fLWonN4XpoxCE7VRhZYqhmggSMxMEJhqJVWZuIcNpKfDV0li2kqkrnHyVmLlkwHfXv), "text/css"});
        rtn.emplace("highlight/styles/base16/equilibrium-gray-light.css", embedded_file{saucer::stash<>::view(f1MJy0Jkn1m1Rg7YARCAxvZQrrYjeoBLjpVPUFo1o1Bb23nicblVdtdKr6O5Ly7IPwoq3VCuwKRYazw0v7DkuUQmawUTJjtGF), "text/css"});
        rtn.emplace("highlight/styles/base16/equilibrium-gray-light.min.css", embedded_file{saucer::stash<>::view(f6NJUXPQtyszSY5FSBYZ9RgDLIDPeJwEApv0itVjrGlhyOQUIzqNuptcn2FJ8n5n7N20YAWGSsUNxKBk3AzrNfB2KwvHj0JOdYYy7X), "text/css"});
        rtn.emplace("highlight/styles/base16/equilibrium-light.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8XSIn8G6HEWXCCEtYyn2LNnUCnuZOwuzwUVgsAFxJkFMpCwcOsBOkioHHv3K0kLFNhSJ36SQO7Qs67), "text/css"});
        rtn.emplace("highlight/styles/base16/equilibrium-light.min.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89iS8L7J7jQVD2naFD7akSSR03pLkVHp6nMDEC3GrjvTklYtXtjMNilBdb6WCBjQIeBlDuu9UcbEE8AgMzv1), "text/css"});
        rtn.emplace("highlight/styles/base16/espresso.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUTnTHBdJqGhHjeP0zhwZ9dXyDrkeXYcaNQCoARgOGok2kOwLGUxfCinUH2wCzjWIQGR), "text/css"});
        rtn.emplace("highlight/styles/base16/espresso.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW0KQOuC7FAmQFFT0IDoOF6LaAnCIA2SJ), "text/css"});
        rtn.emplace("highlight/styles/base16/eva-dim.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LP2xHxgY044XQoxJwQlDTq4UpAIaj4Pl66F), "text/css"});
        rtn.emplace("highlight/styles/base16/eva-dim.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPGZSJQBRPNLrQLOnhPStbpKpCfhrTX), "text/css"});
        rtn.emplace("highlight/styles/base16/eva.css", embedded_file{saucer::stash<>::view(f9WyAbPBHunlndnFRNaGuJBHy4lrjCKXD9JVJ8cfDDbhw4R6Ik60IJLeZGQkPq0nFtE2Evz), "text/css"});
        rtn.emplace("highlight/styles/base16/eva.min.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LP2xHxgY044XQoxJwQlDTq4UpFoDbDkSZiV), "text/css"});
        rtn.emplace("highlight/styles/base16/flat.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVMyJLl3NloVCcC3hdqcun8ISXH1beAaBhPmJu1OKnDbtPVbqRegqOVwPZVS3n), "text/css"});
        rtn.emplace("highlight/styles/base16/flat.min.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUTnTHBdJqGhHjeP0zhwZ9dXyDrkeXYcaNQCoARgOGok2kOwLGUxfazLDB65zVizq1tj), "text/css"});
        rtn.emplace("highlight/styles/base16/framer.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvHmdStgjELBbmlVIp2NNymSx), "text/css"});
        rtn.emplace("highlight/styles/base16/framer.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyOIEvCh75XyVPWdHNdSN), "text/css"});
        rtn.emplace("highlight/styles/base16/fruit-soda.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyOIF3FPN5fWeo3iHIOQ7), "text/css"});
        rtn.emplace("highlight/styles/base16/fruit-soda.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg4Df9nKezyGVcrgQ2mzv0d6TXbBhPFh7e3TqQBpf8weElSqNtvIP3m9xk77Th6RLgbyXFiuxD1), "text/css"});
        rtn.emplace("highlight/styles/base16/gigavolt.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUTnTHBdJqGhHjeP0zhwZ9dXyDrkeXYcaNQCoARgOGok2kOwLGUxfzeYPXVsCIK5pFAJ), "text/css"});
        rtn.emplace("highlight/styles/base16/gigavolt.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW0KQOuC7FAmTweAffnhrCHd3aSMmMCVn), "text/css"});
        rtn.emplace("highlight/styles/base16/github.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvHmdStgjELBdCLsmxmK82zKt), "text/css"});
        rtn.emplace("highlight/styles/base16/github.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyOOrXd4THQaaDz98XwA7), "text/css"});
        rtn.emplace("highlight/styles/base16/google-dark.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPGZSJQBRPNMlK7GZHdZqxSXZAZow3n), "text/css"});
        rtn.emplace("highlight/styles/base16/google-dark.min.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYThQPwRhJHsqAaTf9XWJfObSjyjYJEGo3ZONES8rJswA8xz6Iguc6k3enhY02gc7pXDbJON2txtj), "text/css"});
        rtn.emplace("highlight/styles/base16/google-light.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW0KQOuC7FAmTzP40PgpQ5W1erz3tKGvr), "text/css"});
        rtn.emplace("highlight/styles/base16/google-light.min.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MdJ57KMpdqRPicTvOPRCvagfqm5fOvOgk8dvgCaA6q9t1gI1BBlLqB6TDoOORTdlUafQUpysgk9z), "text/css"});
        rtn.emplace("highlight/styles/base16/grayscale-dark.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg4Df9nKezyGVcrgQ2mzv0d6TXbBhPFh7e3TqQBpf8weElSqNtvIvDlCZHXa7TgD4y2BpqMu3nf), "text/css"});
        rtn.emplace("highlight/styles/base16/grayscale-dark.min.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVG8ras6Tv9yL4MXVQR0TgIGKis5aB1HLlVyr1eLsvWxSFRS2YhnwOU5d7Rh2f923KLP8nOwg1TzXPJD), "text/css"});
        rtn.emplace("highlight/styles/base16/grayscale-light.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYThQPwRhJHsqAaTf9XWJfObSjyjYJEGo3ZONES8rJswA8xz6Iguc8GottgQf8sYI3MOr8pcYUEKp), "text/css"});
        rtn.emplace("highlight/styles/base16/grayscale-light.min.css", embedded_file{saucer::stash<>::view(f1CGTDaSS4GQFt4ebIFOlY1B9014Ll9VyYdPRZHL3NVHdsC3GwocMnY5UdlLmZIsD76FFWkLiztIh5WbF1PVdwKezXvNr), "text/css"});
        rtn.emplace("highlight/styles/base16/green-screen.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW0KQOuC7FAmU0kxTABLy3594LI8eel63), "text/css"});
        rtn.emplace("highlight/styles/base16/green-screen.min.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MdJ57KMpdqRPicTvOPRCvagfqm5fOvOgk8dvgCaA6q9t1gI1BBlSBULBRRD0Icc1r43tM524FZ8l), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-dark-hard.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8XSIn8G6HEWXCCEtYyn2LNnUCnuZOwuzwUVgsAFxJkFMpCwcOsCZwvrQbyMAriIlRnEuxnx6gmDP2x), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-dark-hard.min.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89iS8L7J7jQVD2naFD7akSSR03pLkVHp6nMDEC3GrjvTklYtXtjRusZFCX8wQ9vYb9xfSfL2xiLIsY0oV5mN), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-dark-medium.css", embedded_file{saucer::stash<>::view(f1CGTDaSS4GQFt4ebIFOlY1B9014Ll9VyYdPRZHL3NVHdsC3GwocMnY5UdlLmZIsDIsLkQFDzy61LWNN2ya3ZVvyeZ5e7), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-dark-medium.min.css", embedded_file{saucer::stash<>::view(f5cARlJZCRKHyHvB56IHHRiIwP9QWVCrlEfhEvGZSWtsuVhIFPwAejiQ7GNS6iFePc8dJBSWHs6aie2aLTWPH7busYl3vAkS71), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-dark-pale.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8XSIn8G6HEWXCCEtYyn2LNnUCnuZOwuzwUVgsAFxJkFMpCwcOsCZwvrQbyMAriIlRnEveO7PQsRmmB), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-dark-pale.min.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89iS8L7J7jQVD2naFD7akSSR03pLkVHp6nMDEC3GrjvTklYtXtjRusZFCX8wQ9vYb9xfVsyXVEbnigu8DlPH), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-dark-soft.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8XSIn8G6HEWXCCEtYyn2LNnUCnuZOwuzwUVgsAFxJkFMpCwcOsCZwvrQbyMAriIlRnEvueD6p8rVUx), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-dark-soft.min.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89iS8L7J7jQVD2naFD7akSSR03pLkVHp6nMDEC3GrjvTklYtXtjRusZFCX8wQ9vYb9xfX7Ccn1LGWLs76vaN), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-light-hard.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVG8ras6Tv9yL4MXVQR0TgIGKis5aB1HLlVyr1eLsvWxSFRS2YhnwRKubsnDYsg2KwDaOp9sLYM7Up3j), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-light-hard.min.css", embedded_file{saucer::stash<>::view(f1MJy0Jkn1m1Rg7YARCAxvZQrrYjeoBLjpVPUFo1o1Bb23nicblVdtdKr6O5Ly7fGrJWlkqvE5A1aUOHX5txGeJYtMfpsaX7T), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-light-medium.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPbPDdzLaGKSs1A4PxqhI230j3pfavx3AqdllVyr0Q8akgWBVwXlvqvwPngMro7IRD3DW0WKBMTyf7Jb7zf), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-light-medium.min.css", embedded_file{saucer::stash<>::view(fNBb8dMnLMpmCw05l3zTM2QwD9qvWCr7z2aAXcSQPnqkjKslLf6C0ClPpzcq3iicrlTeJDJlKwS5P9IxiL6yTqpVmLL6uG4205D), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-light-soft.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVG8ras6Tv9yL4MXVQR0TgIGKis5aB1HLlVyr1eLsvWxSFRS2YhnwRKubsnDYsg2KwDaOq6ibYUU8vVj), "text/css"});
        rtn.emplace("highlight/styles/base16/gruvbox-light-soft.min.css", embedded_file{saucer::stash<>::view(f1MJy0Jkn1m1Rg7YARCAxvZQrrYjeoBLjpVPUFo1o1Bb23nicblVdtdKr6O5Ly7fGrJWlkqvE5A1aUOHXALoqTcYr0ThBCMvT), "text/css"});
        rtn.emplace("highlight/styles/base16/hardcore.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUTnTHBdJqGhHjeP0zhwZ9dXyDrkeXYcaNQCoARgOGok2kOwLGUxgNpfU8JikUgBsMSJ), "text/css"});
        rtn.emplace("highlight/styles/base16/hardcore.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW0KQOuC7FAmVm0F2EPOsOQoy79jRK9fn), "text/css"});
        rtn.emplace("highlight/styles/base16/harmonic16-dark.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYThQPwRhJHsqAaTf9XWJfObSjyjYJEGo3ZONES8rJswA8xz6Igue8JmJvMtvbdUmN8VS6xuZGNNL), "text/css"});
        rtn.emplace("highlight/styles/base16/harmonic16-dark.min.css", embedded_file{saucer::stash<>::view(f1CGTDaSS4GQFt4ebIFOlY1B9014Ll9VyYdPRZHL3NVHdsC3GwocMnY5UdlLmZJ1afSX8ZVbMnrxAjIgwvHNDUfMtAjjv), "text/css"});
        rtn.emplace("highlight/styles/base16/harmonic16-light.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MdJ57KMpdqRPicTvOPRCvagfqm5fOvOgk8dvgCaA6q9t1gI1BBtiLfWGsYvrP55jZyNt28xad3eF), "text/css"});
        rtn.emplace("highlight/styles/base16/harmonic16-light.min.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPbPDdzLaGKSs1A4PxqhI230j3pfavx3AqdllVyr0Q8akgWBVwXmYZPBopOcUI9umKWOhYjDAN531KhwHfX), "text/css"});
        rtn.emplace("highlight/styles/base16/heetch-dark.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPGZSJQBRPNNCXwOOQqx47u90DKUWaB), "text/css"});
        rtn.emplace("highlight/styles/base16/heetch-dark.min.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYThQPwRhJHsqAaTf9XWJfObSjyjYJEGo3ZONES8rJswA8xz6IgueAMpbqv9q5wyglL3I1IHcMOdH), "text/css"});
        rtn.emplace("highlight/styles/base16/heetch-light.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW0KQOuC7FAmVno96issdvt9dReQb34ex), "text/css"});
        rtn.emplace("highlight/styles/base16/heetch-light.min.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MdJ57KMpdqRPicTvOPRCvagfqm5fOvOgk8dvgCaA6q9t1gI1BBtqoH6IW0dJv2o0AM5llhZI58EN), "text/css"});
        rtn.emplace("highlight/styles/base16/helios.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvHmdStgjELBedfq5U4e1Kf9n), "text/css"});
        rtn.emplace("highlight/styles/base16/helios.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyOVcIOWWYiyCth9q82Hj), "text/css"});
        rtn.emplace("highlight/styles/base16/hopscotch.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr2Gsy2LvowjEUpI6nRp9nIGfFwdOYxKCiCt98J2DRW7Layto7qR62WQG3VrOyOnE0mp), "text/css"});
        rtn.emplace("highlight/styles/base16/hopscotch.min.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV11N2r7QOhAmLWNLo55J8O079acBxsexUWoKvgaFI9ML0q21ueWJcc0PnBqPVYLLkEhi2eTBr), "text/css"});
        rtn.emplace("highlight/styles/base16/horizon-dark.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW0KQOuC7FAmVsOv9Up8vboFCBbhy0g2l), "text/css"});
        rtn.emplace("highlight/styles/base16/horizon-dark.min.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MdJ57KMpdqRPicTvOPRCvagfqm5fOvOgk8dvgCaA6q9t1gI1BBuCLLGpcZZJzzBFCBk8NicxzFRb), "text/css"});
        rtn.emplace("highlight/styles/base16/horizon-light.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV11N2r7QOhAmLWNLo55J8O079acBxsexUWoKvgaFI9ML0q21ueWJcctzDHArsAJG8CSvlo8fb), "text/css"});
        rtn.emplace("highlight/styles/base16/horizon-light.min.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8XSIn8G6HEWXCCEtYyn2LNnUCnuZOwuzwUVgsAFxJkFMpCwcOsDA2y7pV9GrqnI8eB1uzyMTiaVC0x), "text/css"});
        rtn.emplace("highlight/styles/base16/humanoid-dark.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV11N2r7QOhAmLWNLo55J8O079acBxsexUWoKvgaFI9ML0q21ueWJnuYZSXHnPhW5EGsMq3o7H), "text/css"});
        rtn.emplace("highlight/styles/base16/humanoid-dark.min.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8XSIn8G6HEWXCCEtYyn2LNnUCnuZOwuzwUVgsAFxJkFMpCwcOsDAtsD6LSUFlU5mN3ezyADbwg0Nvf), "text/css"});
        rtn.emplace("highlight/styles/base16/humanoid-light.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg4Df9nKezyGVcrgQ2mzv0d6TXbBhPFh7e3TqQBpf8weElSqNtvJRm5WkPpRU27jK6jxFgwjTJj), "text/css"});
        rtn.emplace("highlight/styles/base16/humanoid-light.min.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVG8ras6Tv9yL4MXVQR0TgIGKis5aB1HLlVyr1eLsvWxSFRS2YhqP0hq6Cbcv64TDFQXzIvYct6LCE9T), "text/css"});
        rtn.emplace("highlight/styles/base16/ia-dark.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LP2xHxgY044XQoxJwQlDUDkJeZVNmGD2nMR), "text/css"});
        rtn.emplace("highlight/styles/base16/ia-dark.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPGZSJQBRPNNePhbaVsgXrFLI8a4gqJ), "text/css"});
        rtn.emplace("highlight/styles/base16/ia-light.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUTnTHBdJqGhHjeP0zhwZ9dXyDrkeXYcaNQCoARgOGok2kOwLGUxgmlFCN7OS2JqYLv1), "text/css"});
        rtn.emplace("highlight/styles/base16/ia-light.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW0KQOuC7FAmXes8GYHrENEMiL6FqyK2d), "text/css"});
        rtn.emplace("highlight/styles/base16/icy-dark.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUTnTHBdJqGhHjeP0zhwZ9dXyDrkeXYcaNQCoARgOGok2kOwLGUxgmz7Va4j0mViaWHL), "text/css"});
        rtn.emplace("highlight/styles/base16/icy-dark.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW0KQOuC7FAmXfvBWiQzzaYeXGLGZk9Lv), "text/css"});
        rtn.emplace("highlight/styles/base16/ir-black.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUTnTHBdJqGhHjeP0zhwZ9dXyDrkeXYcaNQCoARgOGok2kOwLGUxgoPzGtaxK3Bew4YN), "text/css"});
        rtn.emplace("highlight/styles/base16/ir-black.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW0KQOuC7FAmXmdo7MKFaoGMsHDoQD8q3), "text/css"});
        rtn.emplace("highlight/styles/base16/isotope.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LP2xHxgY044XQoxJwQlDUEB2aabBkwvecBX), "text/css"});
        rtn.emplace("highlight/styles/base16/isotope.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPGZSJQBRPNNgQzZE4Dgp5t30HvgJIh), "text/css"});
        rtn.emplace("highlight/styles/base16/kimber.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvHmdStgjELBj3LVlLSMTk5Tv), "text/css"});
        rtn.emplace("highlight/styles/base16/kimber.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyOqJJN5DjqJGOeEh1Z8F), "text/css"});
        rtn.emplace("highlight/styles/base16/london-tube.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPGZSJQBRPNP2zeaSDrDqU01Hxtw91H), "text/css"});
        rtn.emplace("highlight/styles/base16/london-tube.min.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYThQPwRhJHsqAaTf9XWJfObSjyjYJEGo3ZONES8rJswA8xz6IgumouahT48c81ZkM5K3r4zX6ZXf), "text/css"});
        rtn.emplace("highlight/styles/base16/macintosh.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr2Gsy2LvowjEUpI6nRp9nIGfFwdOYxKCiCt98J2DRW7Layto7qZJaADrrcTwzM5QO4R), "text/css"});
        rtn.emplace("highlight/styles/base16/macintosh.min.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV11N2r7QOhAmLWNLo55J8O079acBxsexUWoKvgaFI9ML0q21ueWw9QKhRr5ppt9RNsjpdLZgJ), "text/css"});
        rtn.emplace("highlight/styles/base16/marrakesh.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr2Gsy2LvowjEUpI6nRp9nIGfFwdOYxKCiCt98J2DRW7Layto7qZJbd5faVAeVryEAip), "text/css"});
        rtn.emplace("highlight/styles/base16/marrakesh.min.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV11N2r7QOhAmLWNLo55J8O079acBxsexUWoKvgaFI9ML0q21ueWw9XChYHbcgppOqnkcXcKvr), "text/css"});
        rtn.emplace("highlight/styles/base16/materia.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LP2xHxgY044XQoxJwQlDUbvZmRxr7Qslpul), "text/css"});
        rtn.emplace("highlight/styles/base16/materia.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPGZSJQBRPNPTmSPX5pUuu7BY1r0Kvb), "text/css"});
        rtn.emplace("highlight/styles/base16/material-darker.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYThQPwRhJHsqAaTf9XWJfObSjyjYJEGo3ZONES8rJswA8xz6IguoqUgaLqxWXBtXVSk7PBNBA3uN), "text/css"});
        rtn.emplace("highlight/styles/base16/material-darker.min.css", embedded_file{saucer::stash<>::view(f1CGTDaSS4GQFt4ebIFOlY1B9014Ll9VyYdPRZHL3NVHdsC3GwocMnY5UdlLmZJpoQJh3tBVvpOorCsPLRQRqj0ebJMG3), "text/css"});
        rtn.emplace("highlight/styles/base16/material-lighter.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MdJ57KMpdqRPicTvOPRCvagfqm5fOvOgk8dvgCaA6q9t1gI1BCbwkhq6EfmL386tGhSrgwM4dsqx), "text/css"});
        rtn.emplace("highlight/styles/base16/material-lighter.min.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPbPDdzLaGKSs1A4PxqhI230j3pfavx3AqdllVyr0Q8akgWBVwXptwCfJo3rXqmI9Y06ZwXpjUPsGEP4h0N), "text/css"});
        rtn.emplace("highlight/styles/base16/material-palenight.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVG8ras6Tv9yL4MXVQR0TgIGKis5aB1HLlVyr1eLsvWxSFRS2Yi2NLsAue0MkSR9yh9Bzcpl7xpaN6ax), "text/css"});
        rtn.emplace("highlight/styles/base16/material-palenight.min.css", embedded_file{saucer::stash<>::view(f1MJy0Jkn1m1Rg7YARCAxvZQrrYjeoBLjpVPUFo1o1Bb23nicblVdtdKr6O5Ly8kwL5oq17TzptVyZSu0frblR3FVXvSwmTyN), "text/css"});
        rtn.emplace("highlight/styles/base16/material-vivid.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg4Df9nKezyGVcrgQ2mzv0d6TXbBhPFh7e3TqQBpf8weElSqNtvM07QmWPu4UJpopmfWPodoEM7), "text/css"});
        rtn.emplace("highlight/styles/base16/material-vivid.min.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVG8ras6Tv9yL4MXVQR0TgIGKis5aB1HLlVyr1eLsvWxSFRS2Yi2NLsAue0MkSRK0AV79zy6ScMG3Wx1), "text/css"});
        rtn.emplace("highlight/styles/base16/material.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUTnTHBdJqGhHjeP0zhwZ9dXyDrkeXYcaNQCoARgOGok2kOwLGUxiObjk3T9KlfqWC5j), "text/css"});
        rtn.emplace("highlight/styles/base16/material.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW0KQOuC7FAmfCy5JQe4e0qygqsjwcPFT), "text/css"});
        rtn.emplace("highlight/styles/base16/mellow-purple.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV11N2r7QOhAmLWNLo55J8O079acBxsexUWoKvgaFI9ML0q21ueWwH2Q8UvOzmpsVW9fPBujXn), "text/css"});
        rtn.emplace("highlight/styles/base16/mellow-purple.min.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8XSIn8G6HEWXCCEtYyn2LNnUCnuZOwuzwUVgsAFxJkFMpCwcOsG5FhgNgADgxRReSd0SoYp88R6xpj), "text/css"});
        rtn.emplace("highlight/styles/base16/mexico-light.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW0KQOuC7FAmfEnrib301vUBYXKTKFmGh), "text/css"});
        rtn.emplace("highlight/styles/base16/mexico-light.min.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MdJ57KMpdqRPicTvOPRCvagfqm5fOvOgk8dvgCaA6q9t1gI1BCc5M7wiNwBo8sIk5LCyFFwKtNZL), "text/css"});
        rtn.emplace("highlight/styles/base16/mocha.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLWr1tqHy9QWq5hnICXIgUsGDpOIdRrhQJGRWBJkTrECSnKWGYC3OS0SzMuqY2F), "text/css"});
        rtn.emplace("highlight/styles/base16/mocha.min.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr2Gsy2LvowjEUpI6nRp9nIGfFwdOYxKCiCt98J2DRW7Layto7qZPDX3dKgkWFUqUtDX), "text/css"});
        rtn.emplace("highlight/styles/base16/monokai.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LP2xHxgY044XQoxJwQlDUcG2BFDcvT8Dbfv), "text/css"});
        rtn.emplace("highlight/styles/base16/monokai.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPGZSJQBRPNPVKMrIiz5WJEbi3k3xuF), "text/css"});
        rtn.emplace("highlight/styles/base16/nebula.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvHmdStgjELBnQAKeFLEKxy8h), "text/css"});
        rtn.emplace("highlight/styles/base16/nebula.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyPAmxF4f3qwSmKEW6b3L), "text/css"});
        rtn.emplace("highlight/styles/base16/nord.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVMyJLl3NloVCcC3hdqcun8ISXH1beAaBhPmJu1OKnDbtPVbqRehX2fBfPVAyB), "text/css"});
        rtn.emplace("highlight/styles/base16/nord.min.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUTnTHBdJqGhHjeP0zhwZ9dXyDrkeXYcaNQCoARgOGok2kOwLGUxiovVSf1qT1Bi1eBH), "text/css"});
        rtn.emplace("highlight/styles/base16/nova.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVMyJLl3NloVCcC3hdqcun8ISXH1beAaBhPmJu1OKnDbtPVbqRehX2gQs0iOe3), "text/css"});
        rtn.emplace("highlight/styles/base16/nova.min.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUTnTHBdJqGhHjeP0zhwZ9dXyDrkeXYcaNQCoARgOGok2kOwLGUxiovbIbK9z9IFMhKl), "text/css"});
        rtn.emplace("highlight/styles/base16/ocean.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLWr1tqHy9QWq5hnICXIgUsGDpOIdRrhQJGRWBJkTrECSnKWGYC45NXHZiMO6zr), "text/css"});
        rtn.emplace("highlight/styles/base16/ocean.min.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr2Gsy2LvowjEUpI6nRp9nIGfFwdOYxKCiCt98J2DRW7Layto7qceTB7DdKSD8HjysPz), "text/css"});
        rtn.emplace("highlight/styles/base16/oceanicnext.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPGZSJQBRPNQOfClST4FlBFgguKQADr), "text/css"});
        rtn.emplace("highlight/styles/base16/oceanicnext.min.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYThQPwRhJHsqAaTf9XWJfObSjyjYJEGo3ZONES8rJswA8xz6Igut9AbXsCP18bLYvwwdPsn37nJz), "text/css"});
        rtn.emplace("highlight/styles/base16/one-light.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr2Gsy2LvowjEUpI6nRp9nIGfFwdOYxKCiCt98J2DRW7Layto7qcitf8PFvCCymlJrDX), "text/css"});
        rtn.emplace("highlight/styles/base16/one-light.min.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV11N2r7QOhAmLWNLo55J8O079acBxsexUWoKvgaFI9ML0q21ueXC866yBJlSDKxTnQ0uCjfQh), "text/css"});
        rtn.emplace("highlight/styles/base16/onedark.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LP2xHxgY044XQoxJwQlDUoJwhZud5BnkUSp), "text/css"});
        rtn.emplace("highlight/styles/base16/onedark.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPGZSJQBRPNQPsgmD6pAaNBa2uJeVtr), "text/css"});
        rtn.emplace("highlight/styles/base16/outrun-dark.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPGZSJQBRPNQQf7yT1X5rhUosC2s1rf), "text/css"});
        rtn.emplace("highlight/styles/base16/outrun-dark.min.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYThQPwRhJHsqAaTf9XWJfObSjyjYJEGo3ZONES8rJswA8xz6IgutIXZZvMC3DEtBdTGY97wU03ZD), "text/css"});
        rtn.emplace("highlight/styles/base16/papercolor-dark.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYThQPwRhJHsqAaTf9XWJfObSjyjYJEGo3ZONES8rJswA8xz6IguvGzNZiIGxzq5N9Uz5wrOWNLdb), "text/css"});
        rtn.emplace("highlight/styles/base16/papercolor-dark.min.css", embedded_file{saucer::stash<>::view(f1CGTDaSS4GQFt4ebIFOlY1B9014Ll9VyYdPRZHL3NVHdsC3GwocMnY5UdlLmZKJwcyjTTvb9QVFI7DO3dwLYWpKDndsx), "text/css"});
        rtn.emplace("highlight/styles/base16/papercolor-light.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MdJ57KMpdqRPicTvOPRCvagfqm5fOvOgk8dvgCaA6q9t1gI1BD2U9RLStS3jL4BbGmmNJEdfPsmJ), "text/css"});
        rtn.emplace("highlight/styles/base16/papercolor-light.min.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPbPDdzLaGKSs1A4PxqhI230j3pfavx3AqdllVyr0Q8akgWBVwXruM4wlljZpOvR1918nYTcLVvy8Jsa6xn), "text/css"});
        rtn.emplace("highlight/styles/base16/paraiso.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LP2xHxgY044XQoxJwQlDUu3hmcOTNMSRbMZ), "text/css"});
        rtn.emplace("highlight/styles/base16/paraiso.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPGZSJQBRPNQqmXf6fL7Bp1buByfsOp), "text/css"});
        rtn.emplace("highlight/styles/base16/pasque.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvHmdStgjELBqKGzVbQdZXZdj), "text/css"});
        rtn.emplace("highlight/styles/base16/pasque.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyPOPKCjuRzrLX2FIUVRT), "text/css"});
        rtn.emplace("highlight/styles/base16/phd.css", embedded_file{saucer::stash<>::view(f9WyAbPBHunlndnFRNaGuJBHy4lrjCKXD9JVJ8cfDDbhw4R6Ik60IJLeZGQkPqEu5ssuVWN), "text/css"});
        rtn.emplace("highlight/styles/base16/phd.min.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LP2xHxgY044XQoxJwQlDUuDs0RaVFPDqUi3), "text/css"});
        rtn.emplace("highlight/styles/base16/pico.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVMyJLl3NloVCcC3hdqcun8ISXH1beAaBhPmJu1OKnDbtPVbqRehhYtzgrO9kR), "text/css"});
        rtn.emplace("highlight/styles/base16/pico.min.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUTnTHBdJqGhHjeP0zhwZ9dXyDrkeXYcaNQCoARgOGok2kOwLGUxjcFIcHOI3utbamOJ), "text/css"});
        rtn.emplace("highlight/styles/base16/pop.css", embedded_file{saucer::stash<>::view(f9WyAbPBHunlndnFRNaGuJBHy4lrjCKXD9JVJ8cfDDbhw4R6Ik60IJLeZGQkPqEwIIJ0cYl), "text/css"});
        rtn.emplace("highlight/styles/base16/pop.min.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LP2xHxgY044XQoxJwQlDUuOBW5u3FOd3DVb), "text/css"});
        rtn.emplace("highlight/styles/base16/porple.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvHmdStgjELBqPEbiDIn861HX), "text/css"});
        rtn.emplace("highlight/styles/base16/porple.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyPOmaM4Y2dRXjoM4l5gh), "text/css"});
        rtn.emplace("highlight/styles/base16/qualia.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvHmdStgjELBru5ZouyzA3TTH), "text/css"});
        rtn.emplace("highlight/styles/base16/qualia.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyPVntt0XZYMl1VSSJJLf), "text/css"});
        rtn.emplace("highlight/styles/base16/railscasts.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyPc8ASLVetoDoail7Nit), "text/css"});
        rtn.emplace("highlight/styles/base16/railscasts.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg4Df9nKezyGVcrgQ2mzv0d6TXbBhPFh7e3TqQBpf8weElSqNtvOay3OVvibkEIMsnljQkHM9i7), "text/css"});
        rtn.emplace("highlight/styles/base16/rebecca.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LP2xHxgY044XQoxJwQlDV6EtbBBoH1P4hXv), "text/css"});
        rtn.emplace("highlight/styles/base16/rebecca.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPGZSJQBRPNRlszJUfMSI02INqEgnOF), "text/css"});
        rtn.emplace("highlight/styles/base16/ros-pine-dawn.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV11N2r7QOhAmLWNLo55J8O079acBxsexUWoKvgaFI9ML0q21ueXZXHboZ98SrFQ7P0DbKe1z9), "text/css"});
        rtn.emplace("highlight/styles/base16/ros-pine-dawn.min.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8XSIn8G6HEWXCCEtYyn2LNnUCnuZOwuzwUVgsAFxJkFMpCwcOsJ3Jo5cWXfMrEYNnaOvzPQ0iDllr9), "text/css"});
        rtn.emplace("highlight/styles/base16/ros-pine-moon.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV11N2r7QOhAmLWNLo55J8O079acBxsexUWoKvgaFI9ML0q21ueXZXHboZ98SrFQtbEPFkVmE7), "text/css"});
        rtn.emplace("highlight/styles/base16/ros-pine-moon.min.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8XSIn8G6HEWXCCEtYyn2LNnUCnuZOwuzwUVgsAFxJkFMpCwcOsJ3Jo5cWXfMrEc1kqf9eTrfv1UAR1), "text/css"});
        rtn.emplace("highlight/styles/base16/ros-pine.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUTnTHBdJqGhHjeP0zhwZ9dXyDrkeXYcaNQCoARgOGok2kOwLGUxkQkLGqEq0V1XvwNH), "text/css"});
        rtn.emplace("highlight/styles/base16/ros-pine.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW0KQOuC7FAmokKFSEK8LWGtui1SYy0xf), "text/css"});
        rtn.emplace("highlight/styles/base16/sagelight.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr2Gsy2LvowjEUpI6nRp9nIGfFwdOYxKCiCt98J2DRW7Layto7qjHpI3m1es6ZHAOxGd), "text/css"});
        rtn.emplace("highlight/styles/base16/sagelight.min.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV11N2r7QOhAmLWNLo55J8O079acBxsexUWoKvgaFI9ML0q21ueXgtqMsNaEn2oSKVqzRNx6n5), "text/css"});
        rtn.emplace("highlight/styles/base16/sandcastle.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyPizeb9l1UnrEcNjl0xn), "text/css"});
        rtn.emplace("highlight/styles/base16/sandcastle.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg4Df9nKezyGVcrgQ2mzv0d6TXbBhPFh7e3TqQBpf8weElSqNtvP78nQvsEGjfkhiTU7tN997Vj), "text/css"});
        rtn.emplace("highlight/styles/base16/seti-ui.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LP2xHxgY044XQoxJwQlDVCHiDwj6FbKuEq3), "text/css"});
        rtn.emplace("highlight/styles/base16/seti-ui.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPGZSJQBRPNSEEBS9prpHzaB2dP8O6l), "text/css"});
        rtn.emplace("highlight/styles/base16/shapeshifter.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW0KQOuC7FAmqa5TFF0CZNkRkTpVtcpjX), "text/css"});
        rtn.emplace("highlight/styles/base16/shapeshifter.min.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MdJ57KMpdqRPicTvOPRCvagfqm5fOvOgk8dvgCaA6q9t1gI1BDTGSKTKiZOkWxusVIGisliDPlUh), "text/css"});
        rtn.emplace("highlight/styles/base16/silk-dark.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr2Gsy2LvowjEUpI6nRp9nIGfFwdOYxKCiCt98J2DRW7Layto7qjL3Q353fW9cGPJwN1), "text/css"});
        rtn.emplace("highlight/styles/base16/silk-dark.min.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV11N2r7QOhAmLWNLo55J8O079acBxsexUWoKvgaFI9ML0q21ueXh8ybNT1W7vKOHgr8Lds5qd), "text/css"});
        rtn.emplace("highlight/styles/base16/silk-light.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyPjCw7YivzwZyl8XLYJf), "text/css"});
        rtn.emplace("highlight/styles/base16/silk-light.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg4Df9nKezyGVcrgQ2mzv0d6TXbBhPFh7e3TqQBpf8weElSqNtvP894EKu3cAw8thYJogBWxZND), "text/css"});
        rtn.emplace("highlight/styles/base16/snazzy.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvHmdStgjELBun6qWFgBG9HBj), "text/css"});
        rtn.emplace("highlight/styles/base16/snazzy.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyPjLAupPs4zVoUcMZtdT), "text/css"});
        rtn.emplace("highlight/styles/base16/solar-flare-light.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8XSIn8G6HEWXCCEtYyn2LNnUCnuZOwuzwUVgsAFxJkFMpCwcOsJdqFlAz6w7g0NlLy4lSZzXzNDdqN), "text/css"});
        rtn.emplace("highlight/styles/base16/solar-flare-light.min.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89iS8L7J7jQVD2naFD7akSSR03pLkVHp6nMDEC3GrjvTklYtXtjz1mdDi4wfPYu7nvbc1zGX5zFrPEN7Wu03), "text/css"});
        rtn.emplace("highlight/styles/base16/solar-flare.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPGZSJQBRPNSFKae9SkunSGQ3T87kkl), "text/css"});
        rtn.emplace("highlight/styles/base16/solar-flare.min.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYThQPwRhJHsqAaTf9XWJfObSjyjYJEGo3ZONES8rJswA8xz6Igv1okSioett4PaTo5rPsnGE04Hb), "text/css"});
        rtn.emplace("highlight/styles/base16/solarized-dark.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg4Df9nKezyGVcrgQ2mzv0d6TXbBhPFh7e3TqQBpf8weElSqNtvP8toY6TvBzFt8kwqnxBQSKdH), "text/css"});
        rtn.emplace("highlight/styles/base16/solarized-dark.min.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVG8ras6Tv9yL4MXVQR0TgIGKis5aB1HLlVyr1eLsvWxSFRS2YiH6Vl4nTsjaUjFtl8WT3guIpMncfzf), "text/css"});
        rtn.emplace("highlight/styles/base16/solarized-light.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYThQPwRhJHsqAaTf9XWJfObSjyjYJEGo3ZONES8rJswA8xz6Igv1okSiolY9UvbgChVqX8ZDzjRj), "text/css"});
        rtn.emplace("highlight/styles/base16/solarized-light.min.css", embedded_file{saucer::stash<>::view(f1CGTDaSS4GQFt4ebIFOlY1B9014Ll9VyYdPRZHL3NVHdsC3GwocMnY5UdlLmZKoct8NoJO0Egsrra9PUgffqAIxnIofT), "text/css"});
        rtn.emplace("highlight/styles/base16/spacemacs.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr2Gsy2LvowjEUpI6nRp9nIGfFwdOYxKCiCt98J2DRW7Layto7qjNr1oUkP5JTVWjFeF), "text/css"});
        rtn.emplace("highlight/styles/base16/spacemacs.min.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV11N2r7QOhAmLWNLo55J8O079acBxsexUWoKvgaFI9ML0q21ueXhM6VVlSNLse2LOkCCYf3fX), "text/css"});
        rtn.emplace("highlight/styles/base16/summercamp.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyPjWt0CqritxI9RnybFj), "text/css"});
        rtn.emplace("highlight/styles/base16/summercamp.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg4Df9nKezyGVcrgQ2mzv0d6TXbBhPFh7e3TqQBpf8weElSqNtvP9eaulrawqU0oGmz4YcyjxtT), "text/css"});
        rtn.emplace("highlight/styles/base16/summerfruit-dark.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MdJ57KMpdqRPicTvOPRCvagfqm5fOvOgk8dvgCaA6q9t1gI1BDTiPOf3qGzTKfzsQKPeh8siNHcp), "text/css"});
        rtn.emplace("highlight/styles/base16/summerfruit-dark.min.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPbPDdzLaGKSs1A4PxqhI230j3pfavx3AqdllVyr0Q8akgWBVwXty0sgW1sOVoKeCqXZkOrZCm4ptIz5cXr), "text/css"});
        rtn.emplace("highlight/styles/base16/summerfruit-light.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8XSIn8G6HEWXCCEtYyn2LNnUCnuZOwuzwUVgsAFxJkFMpCwcOsJehMrpXrq9p7NPUil8RqPRJD9Ja7), "text/css"});
        rtn.emplace("highlight/styles/base16/summerfruit-light.min.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89iS8L7J7jQVD2naFD7akSSR03pLkVHp6nMDEC3GrjvTklYtXtjz5ndnYFkbDLpG12wqx6sc4B1KgZD8oZr1), "text/css"});
        rtn.emplace("highlight/styles/base16/synth-midnight-terminal-dark.css", embedded_file{saucer::stash<>::view(f1khg4GZgTGpTZi0ae1wgPBDaqSFGjFELXDUdBPptqebuE2ONWqy5Qkb07Et3pYZcP4lW60RFOaw1GAtsEPeuBuVohAlbu8W5UD7Oaxql), "text/css"});
        rtn.emplace("highlight/styles/base16/synth-midnight-terminal-dark.min.css", embedded_file{saucer::stash<>::view(f8DccIUzro7KVrBfYGROajys5eo4niEzLjx3KcTgAXW03gH2L6V39pd0HodcYLMMEmKID2MITNI3UxGbSSxBtNfNalrz8122iFyQiWHlq4s4fb), "text/css"});
        rtn.emplace("highlight/styles/base16/synth-midnight-terminal-light.css", embedded_file{saucer::stash<>::view(f7EqLhcRLMrUY7RiRJI2J5yK88ad34otEv9iTn8gIbPgW9xsf9ei6QSOmTtTLosl4ZXgCWnoVZYVZCn0hvVwu1BLNKGSaVq10T0vvXdf7b), "text/css"});
        rtn.emplace("highlight/styles/base16/synth-midnight-terminal-light.min.css", embedded_file{saucer::stash<>::view(fXwFS8NzSAwGhXcBZTt7XhrLLMUlpGftJljpl8sY7WO8FCYLf8qD2bB3BZ5bBoCJp1XnBpk4HIAYRoiYfXYP6firPpeuP6TmixODkKfnjr0shox), "text/css"});
        rtn.emplace("highlight/styles/base16/tango.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLWr1tqHy9QWq5hnICXIgUsGDpOIdRrhQJGRWBJkTrECSnKWGYC5r6UHf2miLjP), "text/css"});
        rtn.emplace("highlight/styles/base16/tango.min.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr2Gsy2LvowjEUpI6nRp9nIGfFwdOYxKCiCt98J2DRW7Layto7qkwsQhrfjDG6O4drwB), "text/css"});
        rtn.emplace("highlight/styles/base16/tender.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvHmdStgjELBwCghi8yY5dGgl), "text/css"});
        rtn.emplace("highlight/styles/base16/tender.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyPpxktnvq32Kn38FFM1b), "text/css"});
        rtn.emplace("highlight/styles/base16/tomorrow-night.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg4Df9nKezyGVcrgQ2mzv0d6TXbBhPFh7e3TqQBpf8weElSqNtvPf4RCdSBOVBSqRZmi7EbAKTT), "text/css"});
        rtn.emplace("highlight/styles/base16/tomorrow-night.min.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVG8ras6Tv9yL4MXVQR0TgIGKis5aB1HLlVyr1eLsvWxSFRS2YiJXKqmlzWgPpCWlsdBwVU8W2JbzfgR), "text/css"});
        rtn.emplace("highlight/styles/base16/tomorrow.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUTnTHBdJqGhHjeP0zhwZ9dXyDrkeXYcaNQCoARgOGok2kOwLGUxlEecC9ZTqyd6BfF5), "text/css"});
        rtn.emplace("highlight/styles/base16/tomorrow.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW0KQOuC7FAmsWIf3orFElKrr6kf7kQ6t), "text/css"});
        rtn.emplace("highlight/styles/base16/twilight.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUTnTHBdJqGhHjeP0zhwZ9dXyDrkeXYcaNQCoARgOGok2kOwLGUxlFQs1zDf5VygAkVf), "text/css"});
        rtn.emplace("highlight/styles/base16/twilight.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW0KQOuC7FAmsZwtEYw3uFl93EoptWg9D), "text/css"});
        rtn.emplace("highlight/styles/base16/unikitty-dark.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV11N2r7QOhAmLWNLo55J8O079acBxsexUWoKvgaFI9ML0q21ueXwsWGRzU9GC6sTI8cDTAMeB), "text/css"});
        rtn.emplace("highlight/styles/base16/unikitty-dark.min.css", embedded_file{saucer::stash<>::view(f4M4bVSBDBuF8XSIn8G6HEWXCCEtYyn2LNnUCnuZOwuzwUVgsAFxJkFMpCwcOsKokfP3xqibsOq05VN1lcp4EW6WtH), "text/css"});
        rtn.emplace("highlight/styles/base16/unikitty-light.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg4Df9nKezyGVcrgQ2mzv0d6TXbBhPFh7e3TqQBpf8weElSqNtvQB77DvZsUEs0RlShqZ0Po3Ax), "text/css"});
        rtn.emplace("highlight/styles/base16/unikitty-light.min.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVG8ras6Tv9yL4MXVQR0TgIGKis5aB1HLlVyr1eLsvWxSFRS2YiLxYgxUN7gCOcm3swxmj9fHglSZEIN), "text/css"});
        rtn.emplace("highlight/styles/base16/vulcan.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvHmdStgjELBzDrJ8VTx2cFSV), "text/css"});
        rtn.emplace("highlight/styles/base16/vulcan.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyQ47F0jyj7TNakPHue0Z), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-10-light.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MdJ57KMpdqRPicTvOPRCvagfqm5fOvOgk8dvgCaA6q9t1gI1BE2gcIVWThFOVTxA9BZPMbfqn9EJ), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-10-light.min.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPbPDdzLaGKSs1A4PxqhI230j3pfavx3AqdllVyr0Q8akgWBVwXwbxlPdNP4577TctVp2HHuuKwW88c2aln), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-10.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyQAelU6Ces7hVOsvcVaV), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-10.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg4Df9nKezyGVcrgQ2mzv0d6TXbBhPFh7e3TqQBpf8weElSqNtvRCpUbnzPwOYPcftxCXw4zEWZ), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-95-light.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MdJ57KMpdqRPicTvOPRCvagfqm5fOvOgk8dvgCaA6q9t1gI1BE2gcIVWThFOYi5123KDX0YMyRPv), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-95-light.min.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPbPDdzLaGKSs1A4PxqhI230j3pfavx3AqdllVyr0Q8akgWBVwXwbxlPdNP457Mbql7Gymw0p2nIbxhECsF), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-95.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyQAelU6Ces7hXu7hMe4x), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-95.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg4Df9nKezyGVcrgQ2mzv0d6TXbBhPFh7e3TqQBpf8weElSqNtvRCpUbnzPwOYbMSG5MCLFURuN), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-high-contrast-light.css", embedded_file{saucer::stash<>::view(fQKGU5x159P3lsjfoNij90IJ5vDNuUKQWkNOzND3LxEzZMrN8RMIkgHgATHD2JjtavYKROcF5BINzJH9upgUxMFcox7laPqr0mnK0EV), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-high-contrast-light.min.css", embedded_file{saucer::stash<>::view(f1zQIxhLlQBShYg3lX2l7vdRd9OikujHlPAuVdLibQWS6hewCrOxNCzH1PLDhByEvSZEHyUYxPzu74bnfoEIk34Ntmv6HOPpqHsU2OtopOx6Z), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-high-contrast.css", embedded_file{saucer::stash<>::view(fKQ9Cfb0FRc89iS8L7J7jQVD2naFD7akSSR03pLkVHp6nMDEC3GrjvTklYtXtkA0kllqadUrEL8tclyq64xhNQOJbvsWVjH), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-high-contrast.min.css", embedded_file{saucer::stash<>::view(f1XjtLeY7kEHn3PUNmKTpD03EMKgXUz5My2fLWonN4XpoxCE7VRhZYqhmggSMxPyzIDTVHz2aQkmMOJc1cOi073J6Wty3ZuD4UYNf), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-nt-light.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MdJ57KMpdqRPicTvOPRCvagfqm5fOvOgk8dvgCaA6q9t1gI1BE2gcIVWThFOu8pbDBouHbD9DO3H), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-nt-light.min.css", embedded_file{saucer::stash<>::view(f4we0e6XTtboPbPDdzLaGKSs1A4PxqhI230j3pfavx3AqdllVyr0Q8akgWBVwXwbxlPdNP458z5Ean7ZejzvY34gOobvff), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-nt.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyQAelU6Ces7hoWprIFWN), "text/css"});
        rtn.emplace("highlight/styles/base16/windows-nt.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg4Df9nKezyGVcrgQ2mzv0d6TXbBhPFh7e3TqQBpf8weElSqNtvRCpUbnzPwOZrIaUKbs3qHSi3), "text/css"});
        rtn.emplace("highlight/styles/base16/woodland.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUTnTHBdJqGhHjeP0zhwZ9dXyDrkeXYcaNQCoARgOGok2kOwLGUxmRWH3NGNOMTq4Esd), "text/css"});
        rtn.emplace("highlight/styles/base16/woodland.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW0KQOuC7FAmyBHS0KCBd6av9FNhSDbF5), "text/css"});
        rtn.emplace("highlight/styles/base16/xcode-dusk.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9VccLAhSQyQHMFn8MWY5AhzidCmYd), "text/css"});
        rtn.emplace("highlight/styles/base16/xcode-dusk.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg4Df9nKezyGVcrgQ2mzv0d6TXbBhPFh7e3TqQBpf8weElSqNtvRiFMlhrGhBVVoZdF8pxCRtx5), "text/css"});
        rtn.emplace("highlight/styles/base16/zenburn.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LP2xHxgY044XQoxJwQlDVsaflGVJKCOYEux), "text/css"});
        rtn.emplace("highlight/styles/base16/zenburn.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPGZSJQBRPNVQZ0qCBFw58tODOZwtGN), "text/css"});
        rtn.emplace("highlight/styles/brown-paper.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVMyJLl3NloVCcC3hdqcun8ISXH1beAaBhPmJu1OKnDdlxhD7dXBlMrVNiFcTj), "text/css"});
        rtn.emplace("highlight/styles/brown-paper.min.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUTnTHBdJqGhHjeP0zhwZ9dXyDrkeXYcaNQCoARgOGokBYoNmFVMYrW5Gd6IQmfSSknT), "text/css"});
        rtn.emplace("highlight/styles/brown-papersq.png", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvHn9VyHc7dG6cwIw5qtZKRNv), "image/png"});
        rtn.emplace("highlight/styles/codepen-embed.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvHuqpyG3sA5gfk8NfTsPa3Sl), "text/css"});
        rtn.emplace("highlight/styles/codepen-embed.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9WF8LxARmnxAXITRFKVQd1qIS5n7b), "text/css"});
        rtn.emplace("highlight/styles/color-brewer.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLWr1tqHy9QWq5hnICXIgUsGDpOIdRrhQJGRWBJkTrGBqE3UkcghmC1LaHmvKdP), "text/css"});
        rtn.emplace("highlight/styles/color-brewer.min.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr2Gsy2LvowjEUpI6nRp9nIGfFwdOYxKCiCt98J2DRfRlGicQLonNCS8ulSr5CkModYB), "text/css"});
        rtn.emplace("highlight/styles/dark.css", embedded_file{saucer::stash<>::view(f7OPm7vIuBp2COXuNRP4hnVR3Y4PeiCygKCTJpJtZ10902zqteIPaYP5bJWy8eZ), "text/css"});
        rtn.emplace("highlight/styles/dark.min.css", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzhBYbgTBOrHu6VXIbHy2eQWWNmyHCYRqnfK3dpFSnkS5qKT4FYxWZVYp), "text/css"});
        rtn.emplace("highlight/styles/default.css", embedded_file{saucer::stash<>::view(f8OUOpBG2Ne4qEoke7rZDHkTZTuzAy3OrNrPHNy82YUxls5LE0IlB52txmHmk4TLKSp), "text/css"});
        rtn.emplace("highlight/styles/default.min.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVMyJLl3NloVCcC3hdqcun8ISXH1beAaBhPmJu1OKnEWzw60obcEk99umi5rtr), "text/css"});
        rtn.emplace("highlight/styles/devibeans.css", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1qkJitbMV4e1vesDUnyBuwvWHiECt1qF014cp2RbqvRQD4xEE7ofU43lXH), "text/css"});
        rtn.emplace("highlight/styles/devibeans.min.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvI2LAJgBK8c8A5kQiT18nFbf), "text/css"});
        rtn.emplace("highlight/styles/docco.css", embedded_file{saucer::stash<>::view(fUWoQiic40oj5BM0mn9XQqPniegDw6XaYlPV3ru9Qa8bACNOPmO1exFo62jhha2l), "text/css"});
        rtn.emplace("highlight/styles/docco.min.css", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1qkJitbMV4e1vesDUnyBuwvWHiECt1qF014cp2RbqvVPu9KnluZ9zlarRb), "text/css"});
        rtn.emplace("highlight/styles/far.css", embedded_file{saucer::stash<>::view(f1n1OjVncnMWz7siAWJ9NCTPRV14H7ndsoQGmsZKio8Gi5ZK4l3UPqZ9LAgcUd), "text/css"});
        rtn.emplace("highlight/styles/far.min.css", embedded_file{saucer::stash<>::view(f8OUOpBG2Ne4qEoke7rZDHkTZTuzAy3OrNrPHNy82YUxls5LE0IlBH2XcYeSfm3STh5), "text/css"});
        rtn.emplace("highlight/styles/felipec.css", embedded_file{saucer::stash<>::view(f8OUOpBG2Ne4qEoke7rZDHkTZTuzAy3OrNrPHNy82YUxls5LE0IlBH8MZz2QMswZd2J), "text/css"});
        rtn.emplace("highlight/styles/felipec.min.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVMyJLl3NloVCcC3hdqcun8ISXH1beAaBhPmJu1OKnFRfWWJUK8CvJeaPe2Bzn), "text/css"});
        rtn.emplace("highlight/styles/foundation.css", embedded_file{saucer::stash<>::view(f9WyAbPBHunlndnFRNaGuJBHy4lrjCKXD9JVJ8cfDDbhw4R6Ik60IlAkVkMG3l8T7h9uQxH), "text/css"});
        rtn.emplace("highlight/styles/foundation.min.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LP2xHxgY044ZXGSjCD9Cc9Ezfh9AnjvUxHf), "text/css"});
        rtn.emplace("highlight/styles/github-dark-dimmed.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPSoHNj2FKjW4sPe8Ti2jLc6oAUUstP), "text/css"});
        rtn.emplace("highlight/styles/github-dark-dimmed.min.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYThQPwRhJHsqAaTf9XWJfObSjyjYJEGo3ZONES8rJtrXcdr8doufH2eGsFl8JsBtEUfi9ynvbwaB), "text/css"});
        rtn.emplace("highlight/styles/github-dark.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVMyJLl3NloVCcC3hdqcun8ISXH1beAaBhPmJu1OKnFuRtpELmNMTgp9P7Oby7), "text/css"});
        rtn.emplace("highlight/styles/github-dark.min.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUTnTHBdJqGhHjeP0zhwZ9dXyDrkeXYcaNQCoARgOGoup4YUFYMfcRA1cNIM3Hb3APP1), "text/css"});
        rtn.emplace("highlight/styles/github.css", embedded_file{saucer::stash<>::view(f223UEKeDAZNS9OstFSxO2qQXINyLXv0gxXlIFyZqvlDVS76aoRnCvSoX7vPtLn431), "text/css"});
        rtn.emplace("highlight/styles/github.min.css", embedded_file{saucer::stash<>::view(f9WyAbPBHunlndnFRNaGuJBHy4lrjCKXD9JVJ8cfDDbhw4R6Ik60IrsE0IUSfacrBkgOiYd), "text/css"});
        rtn.emplace("highlight/styles/gml.css", embedded_file{saucer::stash<>::view(f1n1OjVncnMWz7siAWJ9NCTPRV14H7ndsoQGmsZKio8Gi5ZK4l3UPruohZhBgZ), "text/css"});
        rtn.emplace("highlight/styles/gml.min.css", embedded_file{saucer::stash<>::view(f8OUOpBG2Ne4qEoke7rZDHkTZTuzAy3OrNrPHNy82YUxls5LE0IlBNMmkCjTiITY5gp), "text/css"});
        rtn.emplace("highlight/styles/googlecode.css", embedded_file{saucer::stash<>::view(f9WyAbPBHunlndnFRNaGuJBHy4lrjCKXD9JVJ8cfDDbhw4R6Ik60Is2AE9yBhL3KmHlSoNf), "text/css"});
        rtn.emplace("highlight/styles/googlecode.min.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LP2xHxgY044a3Qs1CNfKrG9dH3sytbNVNdD), "text/css"});
        rtn.emplace("highlight/styles/gradient-dark.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvIQ6jiZRWkXgAw29HEgW0tr1), "text/css"});
        rtn.emplace("highlight/styles/gradient-dark.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9YbfVsaJGXkqvJPPhDUgYSvNcPjmd), "text/css"});
        rtn.emplace("highlight/styles/gradient-light.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LP2xHxgY044a3nom2LfEB49CTO7ROwAjABf), "text/css"});
        rtn.emplace("highlight/styles/gradient-light.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPStXPdNvYJNSWrUSJsQ8Dfr8LVsSrD), "text/css"});
        rtn.emplace("highlight/styles/grayscale.css", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1qkJitbMV4e1vesDUnyBuwvWHiECt1qF014cp2Rbr0Vjx4aQf3XHx3CDCd), "text/css"});
        rtn.emplace("highlight/styles/grayscale.min.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvIQ6jktofJBUUVTDzLUfFMX5), "text/css"});
        rtn.emplace("highlight/styles/hybrid.css", embedded_file{saucer::stash<>::view(f223UEKeDAZNS9OstFSxO2qQXINyLXv0gxXlIFyZqvlDVS76aoRnCx1DD1RZUkErZr), "text/css"});
        rtn.emplace("highlight/styles/hybrid.min.css", embedded_file{saucer::stash<>::view(f9WyAbPBHunlndnFRNaGuJBHy4lrjCKXD9JVJ8cfDDbhw4R6Ik60IzA9YCbhz4q20yZ6qjz), "text/css"});
        rtn.emplace("highlight/styles/idea.css", embedded_file{saucer::stash<>::view(f7OPm7vIuBp2COXuNRP4hnVR3Y4PeiCygKCTJpJtZ10902zqteIPaz50vF6s4kl), "text/css"});
        rtn.emplace("highlight/styles/idea.min.css", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzhBYbgTBOrHu6VXIbHy2eQWWNmyHCYRqnfK3dpFSplVwDmfh7QXwrMHb), "text/css"});
        rtn.emplace("highlight/styles/intellij-light.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LP2xHxgY044b5ePhUelBjIdEnGgJc41nXrH), "text/css"});
        rtn.emplace("highlight/styles/intellij-light.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPXirtmhZ2Afvi8BFzHFf21NxTlwEtf), "text/css"});
        rtn.emplace("highlight/styles/ir-black.css", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzhBYbgTBOrHu6VXIbHy2eQWWNmyHCYRqnfK3dpFSpmrEFWGMoncckYMd), "text/css"});
        rtn.emplace("highlight/styles/ir-black.min.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLWr1tqHy9QWq5hnICXIgUsGDpOIdRrhQJGRWBJkTrRX3OYh4qHuTFJRj8KyfB5), "text/css"});
        rtn.emplace("highlight/styles/isbl-editor-dark.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr2Gsy2LvowjEUpI6nRp9nIGfFwdOYxKCiCt98J2DSWf71uF0ry4vBnuaOzdieekKyHb), "text/css"});
        rtn.emplace("highlight/styles/isbl-editor-dark.min.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV11N2r7QOhAmLWNLo55J8O079acBxsexUWoKvgaFIE5YYMg5tQeRwnKvvk5pIEqwwBi9SnsSx), "text/css"});
        rtn.emplace("highlight/styles/isbl-editor-light.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9Zmrl1sDzaq4K8k5eM31oeddJbRwJ), "text/css"});
        rtn.emplace("highlight/styles/isbl-editor-light.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg4Df9nKezyGVcrgQ2mzv0d6TXbBhPFh7e3TqQBpf9GAwftdoKs31OliRCdfa0k23rcmVtpYJbn), "text/css"});
        rtn.emplace("highlight/styles/kimbie-dark.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVMyJLl3NloVCcC3hdqcun8ISXH1beAaBhPmJu1OKnHjmYxDpTWl0Vb5wY3msN), "text/css"});
        rtn.emplace("highlight/styles/kimbie-dark.min.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUTnTHBdJqGhHjeP0zhwZ9dXyDrkeXYcaNQCoARgOGp3OObIsf9DhXQkk6utnEEQ7s83), "text/css"});
        rtn.emplace("highlight/styles/kimbie-light.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLWr1tqHy9QWq5hnICXIgUsGDpOIdRrhQJGRWBJkTrVF2WKX6XvIwcHRJ8ceLmV), "text/css"});
        rtn.emplace("highlight/styles/kimbie-light.min.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr2Gsy2LvowjEUpI6nRp9nIGfFwdOYxKCiCt98J2DSo0ja1xhu4n7YgR5zRjgyMm6vIZ), "text/css"});
        rtn.emplace("highlight/styles/lightfair.css", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1qkJitbMV4e1vesDUnyBuwvWHiECt1qF014cp2Rbr8lKDYm1KkaeIY3fbH), "text/css"});
        rtn.emplace("highlight/styles/lightfair.min.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvJ2n7iNErLAVc6ddBaqGbdrf), "text/css"});
        rtn.emplace("highlight/styles/lioshi.css", embedded_file{saucer::stash<>::view(f223UEKeDAZNS9OstFSxO2qQXINyLXv0gxXlIFyZqvlDVS76aoRnD2mYtgsYUDYwbL), "text/css"});
        rtn.emplace("highlight/styles/lioshi.min.css", embedded_file{saucer::stash<>::view(f9WyAbPBHunlndnFRNaGuJBHy4lrjCKXD9JVJ8cfDDbhw4R6Ik60JQBSihPtnFIlijrZidv), "text/css"});
        rtn.emplace("highlight/styles/magula.css", embedded_file{saucer::stash<>::view(f223UEKeDAZNS9OstFSxO2qQXINyLXv0gxXlIFyZqvlDVS76aoRnD4CSwHbXwhwv4t), "text/css"});
        rtn.emplace("highlight/styles/magula.min.css", embedded_file{saucer::stash<>::view(f9WyAbPBHunlndnFRNaGuJBHy4lrjCKXD9JVJ8cfDDbhw4R6Ik60JWpZKQZm1JDhHSfSZ87), "text/css"});
        rtn.emplace("highlight/styles/mono-blue.css", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1qkJitbMV4e1vesDUnyBuwvWHiECt1qF014cp2RbrASn5XkWDSehkO50XT), "text/css"});
        rtn.emplace("highlight/styles/mono-blue.min.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvJAlYuoebrPuqAApVc4Yl9wR), "text/css"});
        rtn.emplace("highlight/styles/monokai-sublime.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUTnTHBdJqGhHjeP0zhwZ9dXyDrkeXYcaNQCoARgOGp7jBDoDka2QjgzQEbIdmp98nLf), "text/css"});
        rtn.emplace("highlight/styles/monokai-sublime.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW27SdDjzxWJNHyZ7Im8QyMAVQ3SSWvVD), "text/css"});
        rtn.emplace("highlight/styles/monokai.css", embedded_file{saucer::stash<>::view(f8OUOpBG2Ne4qEoke7rZDHkTZTuzAy3OrNrPHNy82YUxls5LE0IlBxg0TnlsItsT3sx), "text/css"});
        rtn.emplace("highlight/styles/monokai.min.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVMyJLl3NloVCcC3hdqcun8ISXH1beAaBhPmJu1OKnIf7BpCbrVSU6Tl5Vzn8N), "text/css"});
        rtn.emplace("highlight/styles/night-owl.css", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1qkJitbMV4e1vesDUnyBuwvWHiECt1qF014cp2RbrC5P894v4SP7Ls3VT9), "text/css"});
        rtn.emplace("highlight/styles/night-owl.min.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvJINFmnlCb49iQ1zKSAHNTn9), "text/css"});
        rtn.emplace("highlight/styles/nnfx-dark.css", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1qkJitbMV4e1vesDUnyBuwvWHiECt1qF014cp2RbrC7PoUheAhyu1VpOSJ), "text/css"});
        rtn.emplace("highlight/styles/nnfx-dark.min.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvJIWgJpT9dPx8d4GQ8ZdWHfn), "text/css"});
        rtn.emplace("highlight/styles/nnfx-light.css", embedded_file{saucer::stash<>::view(f9WyAbPBHunlndnFRNaGuJBHy4lrjCKXD9JVJ8cfDDbhw4R6Ik60Je2caUmGijPk5dPDW9z), "text/css"});
        rtn.emplace("highlight/styles/nnfx-light.min.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LP2xHxgY044dgUwjsWb8HNcKk7ALby4uOcV), "text/css"});
        rtn.emplace("highlight/styles/nord.css", embedded_file{saucer::stash<>::view(f7OPm7vIuBp2COXuNRP4hnVR3Y4PeiCygKCTJpJtZ10902zqteIPbPvNneGGmEF), "text/css"});
        rtn.emplace("highlight/styles/nord.min.css", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzhBYbgTBOrHu6VXIbHy2eQWWNmyHCYRqnfK3dpFSrnMkRHhFxlcfq7zX), "text/css"});
        rtn.emplace("highlight/styles/obsidian.css", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzhBYbgTBOrHu6VXIbHy2eQWWNmyHCYRqnfK3dpFSsB3PJz1bfRYA6UdP), "text/css"});
        rtn.emplace("highlight/styles/obsidian.min.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLWr1tqHy9QWq5hnICXIgUsGDpOIdRrhQJGRWBJkTrcjowig9pWFdRBAZbRTHYB), "text/css"});
        rtn.emplace("highlight/styles/panda-syntax-dark.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9drzhhrNFgBTAi7mMrzQkRJbwofTP), "text/css"});
        rtn.emplace("highlight/styles/panda-syntax-dark.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg4Df9nKezyGVcrgQ2mzv0d6TXbBhPFh7e3TqQBpf9ZJeEe0f6wTHmLTY14iRLhKAnRTUM902uB), "text/css"});
        rtn.emplace("highlight/styles/panda-syntax-light.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPocwmT6O0kBMSEC7iQyUxZ3k4qDmgl), "text/css"});
        rtn.emplace("highlight/styles/panda-syntax-light.min.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYThQPwRhJHsqAaTf9XWJfObSjyjYJEGo3ZONES8rJvVp88TCjkfQvPcg0SRgqRoK00eoBYG3nQ1b), "text/css"});
        rtn.emplace("highlight/styles/paraiso-dark.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLWr1tqHy9QWq5hnICXIgUsGDpOIdRrhQJGRWBJkTrecM1R4HHsmeoKt9QV0loh), "text/css"});
        rtn.emplace("highlight/styles/paraiso-dark.min.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr2Gsy2LvowjEUpI6nRp9nIGfFwdOYxKCiCt98J2DTVy1VsvzwRpltxozzp5kYwV3vlL), "text/css"});
        rtn.emplace("highlight/styles/paraiso-light.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvJXiMvvlfNqCxMM3zgo2Byb5), "text/css"});
        rtn.emplace("highlight/styles/paraiso-light.min.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9drzqFepTlKvz8bE0ghT6gUN9pvWt), "text/css"});
        rtn.emplace("highlight/styles/pojoaque.css", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzhBYbgTBOrHu6VXIbHy2eQWWNmyHCYRqnfK3dpFSsbGy7fHvqBfeV74t), "text/css"});
        rtn.emplace("highlight/styles/pojoaque.jpg", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzhBYbgTBOrHu6VXIbHy2eQWWNmyHCYRqnfK3dpFSsbGy7fHvqBfeX2DX), "image/jpeg"});
        rtn.emplace("highlight/styles/pojoaque.min.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLWr1tqHy9QWq5hnICXIgUsGDpOIdRrhQJGRWBJkTreijotSQllBEWqrRtxzL87), "text/css"});
        rtn.emplace("highlight/styles/purebasic.css", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1qkJitbMV4e1vesDUnyBuwvWHiECt1qF014cp2RbrFUKZaiTO8s6AJaB3z), "text/css"});
        rtn.emplace("highlight/styles/purebasic.min.css", embedded_file{saucer::stash<>::view(fAozejtuXFOLAtexqZuCMvXb5YpX9lV9TU2z6CKwt3jIdXtcsjXvJYK6mr7qyWYJKhABxT1psEV), "text/css"});
        rtn.emplace("highlight/styles/qtcreator-dark.css", embedded_file{saucer::stash<>::view(figYaDWrRHYVQzp976G34faj8xomuK8d7k4KHawV9LP2xHxgY044fFlNPtiyyA3I5kE2k3wFLVg3), "text/css"});
        rtn.emplace("highlight/styles/qtcreator-dark.min.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPrEwAxnd6w3rIoSgMZzFdYQmrmjXSl), "text/css"});
        rtn.emplace("highlight/styles/qtcreator-light.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUTnTHBdJqGhHjeP0zhwZ9dXyDrkeXYcaNQCoARgOGpGL5cgw5jkPVahliV8T1tLpKtv), "text/css"});
        rtn.emplace("highlight/styles/qtcreator-light.min.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW2lpgDGuvUdjw5gZmRS1bzpX1yu7daoF), "text/css"});
        rtn.emplace("highlight/styles/rainbow.css", embedded_file{saucer::stash<>::view(f8OUOpBG2Ne4qEoke7rZDHkTZTuzAy3OrNrPHNy82YUxls5LE0IlCRZ3O82fO0oaatH), "text/css"});
        rtn.emplace("highlight/styles/rainbow.min.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVMyJLl3NloVCcC3hdqcun8ISXH1beAaBhPmJu1OKnKvEY9ixYBRkMyqwTAp1f), "text/css"});
        rtn.emplace("highlight/styles/routeros.css", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzhBYbgTBOrHu6VXIbHy2eQWWNmyHCYRqnfK3dpFStPBda7ZU9s4K1W9D), "text/css"});
        rtn.emplace("highlight/styles/routeros.min.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLWr1tqHy9QWq5hnICXIgUsGDpOIdRrhQJGRWBJkTriUk5WOl8uV5UfKhAOCdHP), "text/css"});
        rtn.emplace("highlight/styles/school-book.css", embedded_file{saucer::stash<>::view(fdM8RmRybyXVMyJLl3NloVCcC3hdqcun8ISXH1beAaBhPmJu1OKnLNmxbolDc6w8GkuZYkbb), "text/css"});
        rtn.emplace("highlight/styles/school-book.min.css", embedded_file{saucer::stash<>::view(f2yVinXrgeeUTnTHBdJqGhHjeP0zhwZ9dXyDrkeXYcaNQCoARgOGpKTwoH8sHLxMP3iD34khvLsrkx), "text/css"});
        rtn.emplace("highlight/styles/shades-of-purple.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr2Gsy2LvowjEUpI6nRp9nIGfFwdOYxKCiCt98J2DTwkJLfYq0PnDVrZBSoEntJMqewd), "text/css"});
        rtn.emplace("highlight/styles/shades-of-purple.min.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV11N2r7QOhAmLWNLo55J8O079acBxsexUWoKvgaFIKkVT0fAPnCvgQu5UtH4vcsLssL1tM3V5), "text/css"});
        rtn.emplace("highlight/styles/srcery.css", embedded_file{saucer::stash<>::view(f223UEKeDAZNS9OstFSxO2qQXINyLXv0gxXlIFyZqvlDVS76aoRnDD4zZnHhdqdNi7), "text/css"});
        rtn.emplace("highlight/styles/srcery.min.css", embedded_file{saucer::stash<>::view(f9WyAbPBHunlndnFRNaGuJBHy4lrjCKXD9JVJ8cfDDbhw4R6Ik60KCSWDjuIfNv5MbnUON1), "text/css"});
        rtn.emplace("highlight/styles/stackoverflow-dark.css", embedded_file{saucer::stash<>::view(f3NUmrGirCrK4pZRxfK3zTQt3c1ROTEy3di2huB9X2kXNO5AaUunPw6ZlVlSs4ex5V85IFccoELKwNldVT), "text/css"});
        rtn.emplace("highlight/styles/stackoverflow-dark.min.css", embedded_file{saucer::stash<>::view(fFq9NEgkD2rYThQPwRhJHsqAaTf9XWJfObSjyjYJEGo3ZONES8rJw4sguOfrcimMv6loWCzxjABRl76vqVtZHoR), "text/css"});
        rtn.emplace("highlight/styles/stackoverflow-light.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW35v9gB9zDHF5yiXNrMVX5v2NES7hfDH), "text/css"});
        rtn.emplace("highlight/styles/stackoverflow-light.min.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MdJ57KMpdqRPicTvOPRCvagfqm5fOvOgk8dvgCaAJo9pArsrPstidnxQazg3y0GhJxrzH2WLIyJf), "text/css"});
        rtn.emplace("highlight/styles/sunburst.css", embedded_file{saucer::stash<>::view(fYf7WVKUDpdTzhBYbgTBOrHu6VXIbHy2eQWWNmyHCYRqnfK3dpFStoiwB9JxVHHuwVhz), "text/css"});
        rtn.emplace("highlight/styles/sunburst.min.css", embedded_file{saucer::stash<>::view(f2cVOsi3WGnyLWr1tqHy9QWq5hnICXIgUsGDpOIdRrhQJGRWBJkTrkQSpmv1Nh0PcTsWLCwwoV), "text/css"});
        rtn.emplace("highlight/styles/tokyo-night-dark.css", embedded_file{saucer::stash<>::view(fCHqyyZpg7rBr2Gsy2LvowjEUpI6nRp9nIGfFwdOYxKCiCt98J2DU5ps1Xf6I9eHK1VCGtJVBtexVC7), "text/css"});
        rtn.emplace("highlight/styles/tokyo-night-dark.min.css", embedded_file{saucer::stash<>::view(fvbgdxjpIXxV11N2r7QOhAmLWNLo55J8O079acBxsexUWoKvgaFILR7W6YxgXdn2utsiOG0HEn6m1rVaUgJ1), "text/css"});
        rtn.emplace("highlight/styles/tokyo-night-light.css", embedded_file{saucer::stash<>::view(fojilm7xNwRcwzNixtiYkMUlrHmm4AtERXQoLq6fQKxQUXDhiIb9gG6B4MzhyxqJWgCoiauL3tD6hLIR), "text/css"});
        rtn.emplace("highlight/styles/tokyo-night-light.min.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg4Df9nKezyGVcrgQ2mzv0d6TXbBhPFh7e3TqQBpf9kVz2Z6MReuIW2wjvVVbMbmCTg79FaI6aJ), "text/css"});
        rtn.emplace("highlight/styles/tomorrow-night-blue.css", embedded_file{saucer::stash<>::view(fDx17jx3Dh6AtwwNSMcqTpX1Kuzx72jnz1xrBHy3MRM9oZRLiheW3Flr0YsrswgsWilJ6dOpC3GHKfnq8Z9), "text/css"});
        rtn.emplace("highlight/styles/tomorrow-night-blue.min.css", embedded_file{saucer::stash<>::view(f13PKhweUnrp8MdJ57KMpdqRPicTvOPRCvagfqm5fOvOgk8dvgCaAKYKs6WeCIhldiOI7KtLWvHxjGVlNuBJqXAB9), "text/css"});
        rtn.emplace("highlight/styles/tomorrow-night-bright.css", embedded_file{saucer::stash<>::view(f3prc50fDoaDg4Df9nKezyGVcrgQ2mzv0d6TXbBhPFh7e3TqQBpf9kVzMGIkYRUMuzcByGjvVaA7UIIYzbpaU7), "text/css"});
        rtn.emplace("highlight/styles/tomorrow-night-bright.min.css", embedded_file{saucer::stash<>::view(fHz90rsMITAEVG8ras6Tv9yL4MXVQR0TgIGKis5aB1HLlVyr1eLszIk2x50oN1Imbd5ZffQFqzuzI8jMjJ92G42MVT1), "text/css"});
        rtn.emplace("highlight/styles/vs.css", embedded_file{saucer::stash<>::view(fQt4XIqDkpTIg6x8MM4gummIliKtUSyWAH19tq9NRdmbnml0BOZweVr38VKF), "text/css"});
        rtn.emplace("highlight/styles/vs.min.css", embedded_file{saucer::stash<>::view(f223UEKeDAZNS9OstFSxO2qQXINyLXv0gxXlIFyZqvlDVS76aoRnDHTWgIJNn6UCNX), "text/css"});
        rtn.emplace("highlight/styles/vs2015.css", embedded_file{saucer::stash<>::view(f223UEKeDAZNS9OstFSxO2qQXINyLXv0gxXlIFyZqvlDVS76aoRnDHTX0JUJqwXDpD), "text/css"});
        rtn.emplace("highlight/styles/vs2015.min.css", embedded_file{saucer::stash<>::view(f9WyAbPBHunlndnFRNaGuJBHy4lrjCKXD9JVJ8cfDDbhw4R6Ik60KX4DsgC4otwYTlLrZzP), "text/css"});
        rtn.emplace("highlight/styles/xcode.css", embedded_file{saucer::stash<>::view(fUWoQiic40oj5BM0mn9XQqPniegDw6XaYlPV3ru9Qa8bACNOPmO1m1nowplp5Dox), "text/css"});
        rtn.emplace("highlight/styles/xcode.min.css", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1qkJitbMV4e1vesDUnyBuwvWHiECt1qF014cp2RbrSfOk6O9EyRD0RPesN), "text/css"});
        rtn.emplace("highlight/styles/xt256.css", embedded_file{saucer::stash<>::view(fUWoQiic40oj5BM0mn9XQqPniegDw6XaYlPV3ru9Qa8bACNOPmO1m3F2UNNSFOrL), "text/css"});
        rtn.emplace("highlight/styles/xt256.min.css", embedded_file{saucer::stash<>::view(f2J7n4DMan7D1qkJitbMV4e1vesDUnyBuwvWHiECt1qF014cp2RbrSm90n69yXiUwRedfv), "text/css"});
        rtn.emplace("html/card.html", embedded_file{saucer::stash<>::view(fIMvMxLtCtgaCsVa5ge0kZWXOruygpQrk6RmYXcfW7n3tztE), "text/html"});
        rtn.emplace("html/index.html", embedded_file{saucer::stash<>::view(f1Dqesn4NxFvpVB4P1U5D6IgLugdGaqMvuMcidTvXLCgieH9Dg), "text/html"});
        rtn.emplace("ico/toolbox.png", embedded_file{saucer::stash<>::view(f1Dqesn4NxFvpVB4P1U5D6IgLugdGaqnO14J7H6JFNKrTPYspL), "image/png"});

        return rtn;
    }
} // namespace saucer::embedded
