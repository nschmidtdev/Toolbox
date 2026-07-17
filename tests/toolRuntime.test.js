'use strict'

const assert = require('node:assert/strict')
const runtime = require('../res/html/tool-runtime.js')

function fakeCard() {
  const classes = new Set()
  const status = { hidden: true }
  return {
    classList: {
      add: value => classes.add(value),
      remove: value => classes.delete(value),
      toggle: (value, enabled) => enabled ? classes.add(value) : classes.delete(value),
      contains: value => classes.has(value),
    },
    dataset: {},
    attributes: {},
    setAttribute(name, value) { this.attributes[name] = value },
    querySelector(selector) {
      return selector === '.tool-running-status' ? status : null
    },
    status,
  }
}

assert.equal(runtime.initialRunning({ singleInstance: true, running: true }), true)
assert.equal(runtime.initialRunning({ singleInstance: false, running: true }), false)

const card = fakeCard()
runtime.applyCardState(card, true)
assert.equal(runtime.isCardRunBlocked(card), true)
assert.equal(card.classList.contains('tool-running'), true)
assert.equal(card.dataset.runDisabled, 'true')
assert.equal(card.attributes['aria-busy'], 'true')
assert.equal(card.status.hidden, false)

runtime.applyCardState(card, false)
assert.equal(runtime.isCardRunBlocked(card), false)
assert.equal(card.classList.contains('tool-running'), false)
assert.equal(card.dataset.runDisabled, 'false')
assert.equal(card.attributes['aria-busy'], 'false')
assert.equal(card.status.hidden, true)
