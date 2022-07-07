local_repository(
    name = "hedron_compile_commands",
    path = "3rdparty/bazel-compile-commands-extractor",
    repo_mapping = {"": ""},
)

load("@hedron_compile_commands//:workspace_setup.bzl", "hedron_compile_commands_setup")

hedron_compile_commands_setup()

local_repository(
    name = "gtest",
    path = "3rdparty/googletest",
    repo_mapping = {"": ""},
)
