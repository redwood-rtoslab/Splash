#!/usr/bin/env bash
echo "Start compile: processing block, factory, sample_main, sample_main_2, sample_main_3"

make -f Makefile.Processing_block clean
make -f Makefile.Factory clean
make -f Makefile.sample_main clean
make -f Makefile.sample_main_2 clean

make -f Makefile.Processing_block
make -f Makefile.Factory
make -f Makefile.sample_main
make -f Makefile.sample_main_2

echo "End compile: processing block, factory, sample_main, sample_main_2, sample_main_3"
