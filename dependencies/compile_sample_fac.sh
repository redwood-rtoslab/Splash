#!/usr/bin/env bash
echo "Start compile"

make -f Makefile.sample_fac clean
make -f Makefile.sample_pb0 clean
make -f Makefile.sample_pb1 clean
make -f Makefile.sample_pb2 clean

make -f Makefile.sample_fac
make -f Makefile.sample_pb0
make -f Makefile.sample_pb1
make -f Makefile.sample_pb2

echo "End compile"
