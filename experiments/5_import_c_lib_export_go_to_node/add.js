'use strict'

const assert = require('assert')
const math = require('bindings')('math')

assert.strictEqual((10 + 3), math.add(10, 3))
