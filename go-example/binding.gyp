{
  "targets": [
    {
      "target_name": "addon",
      "sources": [ "addon.cc" ],
      "include_dirs": ["."],
      "libraries": [
        "<(module_root_dir)/libgoaddon.a"
      ]
    }
  ]
}