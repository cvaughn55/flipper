/* error.h - Standardizes the notion of error handling across all attached devices. */

#ifndef __lf_error_h__
#define __lf_error_h__

/* Success code macros. */
#define lf_success 1
#define lf_error 0

/* Short hand for raising errors based on the truth of a condition. */

#ifdef LF_CONFIG_OMIT_ERRORS
#define lf_assert(cond, err, fmt, ...) if (!(cond)) { goto fail; }
#elif __AVR__
#define lf_assert(cond, err, fmt, ...) if (!(cond)) { _lf_assert(err, __func__, __LINE__, PSTR(fmt), ##__VA_ARGS__); goto fail; }
#else
#define lf_assert(cond, err, fmt, ...) if (!(cond)) { _lf_assert(err, __func__, __LINE__, fmt, ##__VA_ARGS__); goto fail; }
#endif

/* Enumerate all of the error codes. */
typedef enum {
	E_OK,
	E_MALLOC,
	E_NULL,
	E_OVERFLOW,
	E_NO_DEVICE,
	E_NOT_ATTACHED,
	E_ALREADY_ATTACHED,
	E_FS_EXISTS,
	E_FS_NO_FILE,
	E_FMR_OVERFLOW,
	E_FMR,
	E_ENDPOINT,
	E_LIBUSB,
	E_COMMUNICATION,
	E_SOCKET,
	E_MODULE,
	E_RESOULTION,
	E_STRING,
	E_CHECKSUM,
	E_NAME,
	E_CONFIGURATION,
	E_ACK,
	E_TYPE,
	E_BOUNDARY,
	E_TIMER,
	E_TIMEOUT,
	E_NO_PID,
	E_INVALID_TASK,
	E_SUBCLASS,
	E_UNIMPLEMENTED,
	E_TEST,
    E_USB,

	/* uart0 */
	E_UART0_WRITE_TIMEOUT,
	E_UART0_READ_TIMEOUT,

    /* must be kept at the bottom of this enum */
    LF_MAX_ERR
} lf_err_t;

/* Raises an error internally to the current context of libflipper. */
extern void _lf_assert(lf_err_t err, const char *func, int line, const char *format, ...) __attribute__ ((format (printf, 4, 5)));

void lf_error_set(lf_err_t err);
lf_err_t lf_error_get(void);

#endif
