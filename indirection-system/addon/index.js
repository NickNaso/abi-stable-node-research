'use strict'

const assert = require('assert')
const addon = require('bindings')('addon')

assert.strictEqual(5, addon.createInt32())
