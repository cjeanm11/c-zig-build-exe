const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const exe = b.addExecutable(.{
        .name = "zig-build-exe",
        .root_source_file = .{ .path = "src/main.zig" },
        .target = target,
        .optimize = optimize,
    });
    exe.addIncludePath(.{.path = "./include/c"});
    exe.addIncludePath(.{.path = "./include/cpp"});
    exe.addIncludePath(.{.path = "./src/c"});
    exe.addIncludePath(.{.path = "./src/cpp"});
    exe.linkLibC();
    exe.linkLibCpp();
    b.installArtifact(exe);

    const run_cmd = b.addRunArtifact(exe);

    run_cmd.step.dependOn(b.getInstallStep());
    if (b.args) |args| {
        run_cmd.addArgs(args);
    }

    const run_step = b.step("run", "Run the app");
    run_step.dependOn(&run_cmd.step);

    const unit_tests = b.addTest(.{
        .root_source_file = .{ .path = "src/main.zig" },
        .target = target,
        .optimize = optimize,
    });

    const run_unit_tests = b.addRunArtifact(unit_tests);

    const cc = b.addSystemCommand(&.{"cc", "-Iinclude/c", "-c", "src/c/main.c", "-o", "./zig-out/bin/a.out" });
    cc.step.dependOn(b.getInstallStep());
    const run_step_c = b.step("run-c", "Run C");
    run_step_c.dependOn(&cc.step);


    const cpp_cmd = &.{"c++", "-Iinclude/cpp", "src/cpp/main.cpp", "-o", "./zig-out/bin/a.out" };
    const cpp = b.addSystemCommand(cpp_cmd);
        cpp.step.dependOn(b.getInstallStep());
    const run_step_cpp = b.step("run-cpp", "Run C++");
    run_step_cpp.dependOn(&cpp.step);

    const test_step = b.step("test", "Run unit tests");
    test_step.dependOn(&run_unit_tests.step);
}
