{
  "targets": [
    {
      "target_name": "addon",
      "sources": [ "addon.cc" ],
      "include_dirs": ["."],
      "libraries": [
        "<(module_root_dir)/libgoaddon.a",
        #"<(module_root_dir)/libjs_native_callback.a"
      ]
    }
  ]
}