# The Bazel 8.x Learning Path: Polyglot Engineering (C++, Go, Python)
## 1. [Foundations & Philosophy (Bazelisk & Versioning)](01/01.md)
- [x] The Bazel Philosophy: Hermeticity, Reproducibility, and Scalability.
- [x] Architecture: The Client-Server model (Bazel server, JVM).
- [x] Environment Setup (The Right Way):
	- [x] Installing Bazelisk (the recommended launcher/wrapper).
	- [x] Understanding why you shouldn't install bazel directly.
- [x] Version Management:
	- [x] Creating the .bazelversion file.
	- [x] Pinning a specific version (e.g., 8.0.0).
	- [x] How Bazelisk reads .bazelversion to auto-download the correct binary.
- [x] Core Terminology: Workspace vs. Module, Packages, Targets, Rules, Labels, and Actions.
- [x] Project Structure (Bzlmod focus):
	- [x] MODULE.bazel: The new standard for dependency management.
	- [x] BUILD.bazel: Defining package boundaries.
	- [x] .bazelrc: Managing flags and configurations.

## 2. Dependency Management (Bzlmod)
- [x] Introduction to Bzlmod: The Bazel Central Registry (BCR).
- [x] Declaring External Dependencies:
	- [x] Using bazel_dep.
	- [x] Versioning and overrides (git_override, local_path_override).
- [x] Lockfiles: Understanding MODULE.bazel.lock.
- [x] Vendor Mode: Vendoring dependencies for offline builds.

## 3. Polyglot Builds: Language Specifics
- [ ] C++ Development:
	- [ ] Rules: cc_library, cc_binary, cc_test, cc_import.
	- [ ] Managing headers/includes (hdrs, includes, strip_include_prefix).
	- [ ] Linking external system libraries.
- [ ] Go Development:
	- [ ] Setup: rules_go.
	- [ ] The Ecosystem: Why you need Gazelle for dependency resolution.
	- [ ] Generating BUILD files automatically with Gazelle.
- [ ] Python Development:
	- [ ] Setup: rules_python.
	- [ ] Managing Pip dependencies (pip.parse extension).
	- [ ] Creating hermetic Python toolchains.

## 4. The "Glue": Protobuf & gRPC
- [ ] Concept: Single source of truth for APIs.
- [ ] Defining Schemas: The proto_library rule.
- [ ] Code Generation Aspects:
	- [ ] Generating C++ bindings (cc_proto_library, cc_grpc_library).
	- [ ] Generating Go bindings (go_proto_library with compilers).
	- [ ] Generating Python bindings.
- [ ] Cross-Language Integration:
	- [ ] Building a C++ gRPC server.
	- [ ] Building a Python/Go gRPC client.
	- [ ] Linking them together in the dependency graph.

## 5. Daily Usage & Workflow Efficiency
- [ ] Target Patterns: Mastering wildcards (//foo/..., :all).
- [ ] Debugging Builds:
	- [ ] Understanding errors: "Sandboxing disabled", "Missing input file".
	- [ ] Using --verbose_failures and --subcommands.
- [ ] Code Health & Formatting:
	- [ ] Using Buildifier to lint and format BUILD files.
	- [ ] Conventional naming for targets.
- [ ] Test Engineering:
	- [ ] bazel test: Caching test results and flaky tests.
	- [ ] Test suites and size (small, medium, large).
	- [ ] Coverage reports (bazel coverage).

## 6. Visibility, Queries & Graph Analysis
- [ ] Visibility Control: package_group and visibility attributes (enforcing architecture).
- [ ] Bazel Query Language:
	- [ ] bazel query: Exploring the graph (deps(), rdeps(), somepath()).
	- [ ] Practical use case: "Why does target X depend on target Y?"
- [ ] Advanced Queries:
	- [ ] cquery (Configurable Query): Analyzing the graph after configuration (flags) are applied.
	- [ ] aquery (Action Graph Query): Inspecting the exact command lines executed.

## 7. Configuration & Platforms
- [ ] Configurability:
	- [ ] select(): Conditional compilation based on flags.
	- [ ] Defining custom build flags (build_setting).
- [ ] Platforms & Toolchains:
	- [ ] Understanding platforms, constraint_values, and toolchains.
	- [ ] Cross-Compilation: Building a Linux binary from macOS.
	- [ ] Hermetic Toolchains: ensuring the C++ compiler is exactly the same on every machine.

## 8. Extensibility (Starlark)
- [ ] Macros:
	- [ ] Reducing boilerplate in BUILD files.
	- [ ] Symbolic macros (New in Bazel 8).
- [ ] Custom Rules:
	- [ ] The ctx object, actions, and providers.
	- [ ] Writing a simple custom rule (e.g., a file generator).
- [ ] Aspects:
	- [ ] Traversing the graph to generate side-data (e.g., IDE support files, Docker images).

## 9. Performance & Remote Execution
- [ ] Local Optimization:
	- [ ] The Sandbox strategy (tmpfs).
	- [ ] Workers and persistent workers.
- [ ] Remote Caching:
	- [ ] Setting up a read/write remote cache (e.g., Nginx, GCS).
	- [ ] Build Event Protocol (BEP) and Build Scanning.
- [ ] Remote Build Execution (RBE):
	- [ ] Concept of executing actions on a cluster.

## 10. Advanced Integration
- [ ] Docker/OCI Images: Using rules_oci to package Go/C++ binaries containerlessly.
- [ ] CI/CD Integration: Github Actions / GitLab CI with Bazel caches.
- [ ] Migration Strategies: Moving large C++/Python repos to Bazel incrementally.