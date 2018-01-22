/*
 * Adapted from ISL's isl_polyhedron_sample example
 */

#include <assert.h>
#include <isl/vec.h>
#include <isl/set.h>

int main(int argc, char **argv)
{
	struct isl_ctx *ctx = isl_ctx_alloc();
	struct isl_basic_set *bset;

	bset = isl_basic_set_read_from_file(ctx, stdin);

	isl_printer *p;
	p = isl_printer_to_file(ctx, stdout);
	p = isl_printer_print_basic_set(p, bset);
	p = isl_printer_end_line(p);
	isl_printer_free(p);

	if (isl_basic_set_plain_is_empty(bset)) {
		printf("empty\n");
	}
	else {
		printf("elements\n");
	}  

	isl_basic_set_free(bset);
	isl_ctx_free(ctx);

	return 0;
}
