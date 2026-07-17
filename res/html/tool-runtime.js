(function (root, factory) {
    const api = factory();
    if (typeof module === 'object' && module.exports) {
        module.exports = api;
    }
    root.ToolRuntime = api;
}(typeof globalThis !== 'undefined' ? globalThis : this, function () {
    'use strict';

    function initialRunning(item) {
        return item?.singleInstance === true && item?.running === true;
    }

    function isCardRunBlocked(card) {
        return card?.dataset?.runDisabled === 'true';
    }

    function applyCardState(card, running) {
        if (!card) {
            return;
        }
        const active = running === true;
        card.classList.toggle('tool-running', active);
        card.dataset.runDisabled = active ? 'true' : 'false';
        card.setAttribute('aria-busy', active ? 'true' : 'false');
        const status = card.querySelector('.tool-running-status');
        if (status) {
            status.hidden = !active;
        }
    }

    return { initialRunning, isCardRunBlocked, applyCardState };
}));
