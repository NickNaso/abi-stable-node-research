{
  "targets": [
    {
      "target_name": "addon",
      "sources": [ "addon.cc" ],
      "include_dirs": ["."],
      "libraries": [
        "<(module_root_dir)/libgoaddon.a"
      ],
      'conditions' : [
        [ 'OS=="mac"', {
            'cflags+': ['-fvisibility=hidden'],
            "xcode_settings": {
                'CLANG_CXX_LIBRARY' : "libc++",
                'MACOSX_DEPLOYMENT_TARGET' : '10.7',
                'GCC_SYMBOLS_PRIVATE_EXTERN': 'YES', # -fvisibility=hidden
            }
        }]
      ]
    }
  ]
}