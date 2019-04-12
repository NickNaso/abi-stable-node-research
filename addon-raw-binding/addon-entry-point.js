'use strict'

const { writeFile } = require('fs')
const { promisify } = require('util')
const writeOnFile = promisify(writeFile)
const path = require('path')

const tpl =` 
#include <node_api.h>
#include <libgoaddon.h>

NAPI_MODULE(NODE_GYP_MODULE_NAME, Initialize)
`

async function run() {
    await writeOnFile(path.join(__dirname, 'addon.cc'), tpl)
    process.exit(0)
}

const errorHandler = err => {
    console.error('Error happened creatint enty point for the addon.')
    console.error(err)
    process.exit(-1)
}

run().catch(errorHandler)