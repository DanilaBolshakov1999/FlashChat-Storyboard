#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "absl/algorithm/algorithm.h"
#import "absl/algorithm/container.h"
#import "absl/base/internal/atomic_hook.h"
#import "absl/base/call_once.h"
#import "absl/base/casts.h"
#import "absl/base/internal/cycleclock.h"
#import "absl/base/internal/low_level_scheduling.h"
#import "absl/base/internal/per_thread_tls.h"
#import "absl/base/internal/spinlock.h"
#import "absl/base/internal/sysinfo.h"
#import "absl/base/internal/thread_identity.h"
#import "absl/base/internal/tsan_mutex_interface.h"
#import "absl/base/internal/unscaledcycleclock.h"
#import "absl/base/internal/hide_ptr.h"
#import "absl/base/internal/identity.h"
#import "absl/base/internal/inline_variable.h"
#import "absl/base/internal/invoke.h"
#import "absl/base/internal/scheduling_mode.h"
#import "absl/base/config.h"
#import "absl/base/options.h"
#import "absl/base/policy_checks.h"
#import "absl/base/attributes.h"
#import "absl/base/const_init.h"
#import "absl/base/internal/thread_annotations.h"
#import "absl/base/macros.h"
#import "absl/base/optimization.h"
#import "absl/base/port.h"
#import "absl/base/thread_annotations.h"
#import "absl/base/dynamic_annotations.h"
#import "absl/base/internal/dynamic_annotations.h"
#import "absl/base/internal/endian.h"
#import "absl/base/internal/unaligned_access.h"
#import "absl/base/internal/errno_saver.h"
#import "absl/base/internal/fast_type_id.h"
#import "absl/base/log_severity.h"
#import "absl/base/internal/direct_mmap.h"
#import "absl/base/internal/low_level_alloc.h"
#import "absl/base/internal/prefetch.h"
#import "absl/base/internal/pretty_function.h"
#import "absl/base/internal/raw_logging.h"
#import "absl/base/internal/spinlock_akaros.inc"
#import "absl/base/internal/spinlock_linux.inc"
#import "absl/base/internal/spinlock_posix.inc"
#import "absl/base/internal/spinlock_wait.h"
#import "absl/base/internal/spinlock_win32.inc"
#import "absl/base/internal/strerror.h"
#import "absl/base/internal/throw_delegate.h"
#import "absl/cleanup/cleanup.h"
#import "absl/cleanup/internal/cleanup.h"
#import "absl/container/internal/common.h"
#import "absl/container/internal/compressed_tuple.h"
#import "absl/container/internal/container_memory.h"
#import "absl/container/fixed_array.h"
#import "absl/container/flat_hash_map.h"
#import "absl/container/flat_hash_set.h"
#import "absl/container/internal/hash_function_defaults.h"
#import "absl/container/internal/hash_policy_traits.h"
#import "absl/container/internal/hashtable_debug_hooks.h"
#import "absl/container/internal/hashtablez_sampler.h"
#import "absl/container/inlined_vector.h"
#import "absl/container/internal/inlined_vector.h"
#import "absl/container/internal/layout.h"
#import "absl/container/internal/raw_hash_map.h"
#import "absl/container/internal/raw_hash_set.h"
#import "absl/debugging/internal/address_is_readable.h"
#import "absl/debugging/internal/elf_mem_image.h"
#import "absl/debugging/internal/vdso_support.h"
#import "absl/debugging/internal/demangle.h"
#import "absl/debugging/internal/stacktrace_aarch64-inl.inc"
#import "absl/debugging/internal/stacktrace_arm-inl.inc"
#import "absl/debugging/internal/stacktrace_config.h"
#import "absl/debugging/internal/stacktrace_emscripten-inl.inc"
#import "absl/debugging/internal/stacktrace_generic-inl.inc"
#import "absl/debugging/internal/stacktrace_powerpc-inl.inc"
#import "absl/debugging/internal/stacktrace_riscv-inl.inc"
#import "absl/debugging/internal/stacktrace_unimplemented-inl.inc"
#import "absl/debugging/internal/stacktrace_win32-inl.inc"
#import "absl/debugging/internal/stacktrace_x86-inl.inc"
#import "absl/debugging/stacktrace.h"
#import "absl/debugging/internal/symbolize.h"
#import "absl/debugging/symbolize.h"
#import "absl/debugging/symbolize_darwin.inc"
#import "absl/debugging/symbolize_elf.inc"
#import "absl/debugging/symbolize_emscripten.inc"
#import "absl/debugging/symbolize_unimplemented.inc"
#import "absl/debugging/symbolize_win32.inc"
#import "absl/functional/any_invocable.h"
#import "absl/functional/internal/any_invocable.h"
#import "absl/functional/bind_front.h"
#import "absl/functional/internal/front_binder.h"
#import "absl/functional/function_ref.h"
#import "absl/functional/internal/function_ref.h"
#import "absl/hash/internal/city.h"
#import "absl/hash/hash.h"
#import "absl/hash/internal/hash.h"
#import "absl/hash/internal/low_level_hash.h"
#import "absl/memory/memory.h"
#import "absl/meta/type_traits.h"
#import "absl/numeric/bits.h"
#import "absl/numeric/internal/bits.h"
#import "absl/numeric/int128.h"
#import "absl/numeric/int128_have_intrinsic.inc"
#import "absl/numeric/int128_no_intrinsic.inc"
#import "absl/numeric/internal/representation.h"
#import "absl/profiling/internal/exponential_biased.h"
#import "absl/profiling/internal/sample_recorder.h"
#import "absl/random/bernoulli_distribution.h"
#import "absl/random/beta_distribution.h"
#import "absl/random/discrete_distribution.h"
#import "absl/random/distributions.h"
#import "absl/random/exponential_distribution.h"
#import "absl/random/gaussian_distribution.h"
#import "absl/random/log_uniform_int_distribution.h"
#import "absl/random/poisson_distribution.h"
#import "absl/random/uniform_int_distribution.h"
#import "absl/random/uniform_real_distribution.h"
#import "absl/random/zipf_distribution.h"
#import "absl/random/internal/distribution_caller.h"
#import "absl/random/internal/fast_uniform_bits.h"
#import "absl/random/internal/fastmath.h"
#import "absl/random/internal/generate_real.h"
#import "absl/random/internal/iostream_state_saver.h"
#import "absl/random/internal/nonsecure_base.h"
#import "absl/random/internal/pcg_engine.h"
#import "absl/random/internal/platform.h"
#import "absl/random/internal/randen_traits.h"
#import "absl/random/internal/pool_urbg.h"
#import "absl/random/internal/randen.h"
#import "absl/random/internal/randen_engine.h"
#import "absl/random/internal/randen_detect.h"
#import "absl/random/internal/randen_hwaes.h"
#import "absl/random/internal/randen_hwaes.h"
#import "absl/random/internal/randen_slow.h"
#import "absl/random/internal/salted_seed_seq.h"
#import "absl/random/internal/seed_material.h"
#import "absl/random/internal/traits.h"
#import "absl/random/internal/uniform_helper.h"
#import "absl/random/internal/wide_multiply.h"
#import "absl/random/random.h"
#import "absl/random/seed_gen_exception.h"
#import "absl/random/seed_sequences.h"
#import "absl/status/internal/status_internal.h"
#import "absl/status/status.h"
#import "absl/status/status_payload_printer.h"
#import "absl/status/internal/statusor_internal.h"
#import "absl/status/statusor.h"
#import "absl/strings/cord.h"
#import "absl/strings/cord_analysis.h"
#import "absl/strings/cord_buffer.h"
#import "absl/strings/internal/cord_data_edge.h"
#import "absl/strings/internal/cord_internal.h"
#import "absl/strings/internal/cord_rep_btree.h"
#import "absl/strings/internal/cord_rep_btree_navigator.h"
#import "absl/strings/internal/cord_rep_btree_reader.h"
#import "absl/strings/internal/cord_rep_consume.h"
#import "absl/strings/internal/cord_rep_crc.h"
#import "absl/strings/internal/cord_rep_flat.h"
#import "absl/strings/internal/cord_rep_ring.h"
#import "absl/strings/internal/cord_rep_ring_reader.h"
#import "absl/strings/internal/cordz_functions.h"
#import "absl/strings/internal/cordz_handle.h"
#import "absl/strings/internal/cordz_info.h"
#import "absl/strings/internal/cordz_statistics.h"
#import "absl/strings/internal/cordz_update_scope.h"
#import "absl/strings/internal/cordz_update_tracker.h"
#import "absl/strings/internal/char_map.h"
#import "absl/strings/internal/escaping.h"
#import "absl/strings/internal/ostringstream.h"
#import "absl/strings/internal/resize_uninitialized.h"
#import "absl/strings/internal/utf8.h"
#import "absl/strings/str_format.h"
#import "absl/strings/internal/str_format/arg.h"
#import "absl/strings/internal/str_format/bind.h"
#import "absl/strings/internal/str_format/checker.h"
#import "absl/strings/internal/str_format/extension.h"
#import "absl/strings/internal/str_format/float_conversion.h"
#import "absl/strings/internal/str_format/output.h"
#import "absl/strings/internal/str_format/parser.h"
#import "absl/strings/ascii.h"
#import "absl/strings/charconv.h"
#import "absl/strings/escaping.h"
#import "absl/strings/internal/charconv_bigint.h"
#import "absl/strings/internal/charconv_parse.h"
#import "absl/strings/internal/memutil.h"
#import "absl/strings/internal/stl_type_traits.h"
#import "absl/strings/internal/str_join_internal.h"
#import "absl/strings/internal/str_split_internal.h"
#import "absl/strings/internal/string_constant.h"
#import "absl/strings/match.h"
#import "absl/strings/numbers.h"
#import "absl/strings/str_cat.h"
#import "absl/strings/str_join.h"
#import "absl/strings/str_replace.h"
#import "absl/strings/str_split.h"
#import "absl/strings/string_view.h"
#import "absl/strings/strip.h"
#import "absl/strings/substitute.h"
#import "absl/synchronization/internal/graphcycles.h"
#import "absl/synchronization/internal/kernel_timeout.h"
#import "absl/synchronization/barrier.h"
#import "absl/synchronization/blocking_counter.h"
#import "absl/synchronization/internal/create_thread_identity.h"
#import "absl/synchronization/internal/futex.h"
#import "absl/synchronization/internal/per_thread_sem.h"
#import "absl/synchronization/internal/waiter.h"
#import "absl/synchronization/mutex.h"
#import "absl/synchronization/notification.h"
#import "absl/time/internal/cctz/include/cctz/civil_time.h"
#import "absl/time/internal/cctz/include/cctz/civil_time_detail.h"
#import "absl/time/internal/cctz/include/cctz/time_zone.h"
#import "absl/time/internal/cctz/include/cctz/zone_info_source.h"
#import "absl/time/internal/cctz/src/time_zone_fixed.h"
#import "absl/time/internal/cctz/src/time_zone_if.h"
#import "absl/time/internal/cctz/src/time_zone_impl.h"
#import "absl/time/internal/cctz/src/time_zone_info.h"
#import "absl/time/internal/cctz/src/time_zone_libc.h"
#import "absl/time/internal/cctz/src/time_zone_posix.h"
#import "absl/time/internal/cctz/src/tzfile.h"
#import "absl/time/civil_time.h"
#import "absl/time/clock.h"
#import "absl/time/internal/get_current_time_chrono.inc"
#import "absl/time/internal/get_current_time_posix.inc"
#import "absl/time/time.h"
#import "absl/types/any.h"
#import "absl/types/bad_any_cast.h"
#import "absl/types/bad_any_cast.h"
#import "absl/types/bad_optional_access.h"
#import "absl/types/bad_variant_access.h"
#import "absl/types/compare.h"
#import "absl/types/internal/optional.h"
#import "absl/types/optional.h"
#import "absl/types/internal/span.h"
#import "absl/types/span.h"
#import "absl/types/internal/variant.h"
#import "absl/types/variant.h"
#import "absl/utility/utility.h"

FOUNDATION_EXPORT double abslVersionNumber;
FOUNDATION_EXPORT const unsigned char abslVersionString[];

