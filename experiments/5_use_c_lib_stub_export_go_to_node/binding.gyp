{
  "targets": [
    {
      "target_name": "math",
      "sources": [ "math.cc" ],
      #"include_dirs": ["."],
      "libraries": [
        "<(module_root_dir)/libsum.a",
        "<(module_root_dir)/libmath.a",
      ]
    }
  ]
}