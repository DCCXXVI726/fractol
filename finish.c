/* Finalization */
frac->error = clFlush(frac->command_queue);
frac->error = clFinish(frac->command_queue);
frac->error = clReleaseKernel(frac->kernel);
frac->error = clReleaseProgram(frac->program);
frac->error = clReleaseMemObject(frac->memobj);
frac->error = clReleaseCommandQueue(frac->command_queue);
frac->error = clReleaseContext(frac->context);
