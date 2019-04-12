'use strict'

const assert = require('assert')
const addon = require('bindings')('addon')

console.log(addon.createInt32)
assert.strictEqual(5, addon.createInt32())
