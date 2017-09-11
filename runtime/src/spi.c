#include <flipper/libflipper.h>

#ifdef __use_spi__
#define __private_include__
#include <flipper/spi.h>

LF_MODULE(_spi, "spi", "Provides control over the device's SPI bus.");

/* Define the virtual interface for this module. */
const struct _spi spi = {
	spi_configure,
	spi_enable,
	spi_disable,
	spi_ready,
	spi_put,
	spi_get,
	spi_push,
	spi_pull,
};

LF_WEAK int spi_configure() {
	return lf_invoke(&_spi, _spi_configure, NULL);
}

LF_WEAK void spi_enable(void) {
	lf_invoke(&_spi, _spi_enable, NULL);
}

LF_WEAK void spi_disable(void) {
	lf_invoke(&_spi, _spi_disable, NULL);
}

LF_WEAK uint8_t spi_ready(void) {
	return lf_invoke(&_spi, _spi_ready, NULL);
}

LF_WEAK void spi_put(uint8_t byte) {
	lf_invoke(&_spi, _spi_put, fmr_args(fmr_infer(byte)));
}

LF_WEAK uint8_t spi_get(void) {
	return lf_invoke(&_spi, _spi_get, NULL);
}

LF_WEAK int spi_push(void *source, uint32_t length) {
	return lf_push(&_spi, _spi_push, source, length, NULL);
}

LF_WEAK int spi_pull(void *destination, uint32_t length) {
	return lf_pull(&_spi, _spi_pull, destination, length, NULL);
}

#endif