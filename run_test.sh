#!/bin/bash
make test
echo -e
echo -e
echo -e
echo -e
echo -e
echo "	starting tests"
echo "========================================================================="
echo -e > newalgo_out
echo -e > dividecon_out
echo -e > jarvis_out
echo -e > graham_out
echo -e
echo -e
echo "	testing using 10 random points within square bounding box"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 10 10 >> newalgo_out
./test newalgo 10 10 >> newalgo_out
./test newalgo 10 10 >> newalgo_out
./test newalgo 10 10 >> newalgo_out
./test newalgo 10 10 >> newalgo_out
./test newalgo 10 10 >> newalgo_out
./test newalgo 10 10 >> newalgo_out
echo "divideconquer"
./test divideconquer 10 10 >> dividecon_out
./test divideconquer 10 10 >> dividecon_out
./test divideconquer 10 10 >> dividecon_out
./test divideconquer 10 10 >> dividecon_out
./test divideconquer 10 10 >> dividecon_out
./test divideconquer 10 10 >> dividecon_out
./test divideconquer 10 10 >> dividecon_out
echo "jarvis"
./test jarvis 10 10 >> jarvis_out
./test jarvis 10 10 >> jarvis_out
./test jarvis 10 10 >> jarvis_out
./test jarvis 10 10 >> jarvis_out
./test jarvis 10 10 >> jarvis_out
./test jarvis 10 10 >> jarvis_out
./test jarvis 10 10 >> jarvis_out
echo "graham"
./test graham 10 10 >> graham_out
./test graham 10 10 >> graham_out
./test graham 10 10 >> graham_out
./test graham 10 10 >> graham_out
./test graham 10 10 >> graham_out
./test graham 10 10 >> graham_out
./test graham 10 10 >> graham_out
echo -e
echo -e
echo "	testing using 100 random points within square bounding box"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 100 100 >> newalgo_out
./test newalgo 100 100 >> newalgo_out
./test newalgo 100 100 >> newalgo_out
./test newalgo 100 100 >> newalgo_out
./test newalgo 100 100 >> newalgo_out
./test newalgo 100 100 >> newalgo_out
./test newalgo 100 100 >> newalgo_out
echo "divideconquer"
./test divideconquer 100 100 >> dividecon_out
./test divideconquer 100 100 >> dividecon_out
./test divideconquer 100 100 >> dividecon_out
./test divideconquer 100 100 >> dividecon_out
./test divideconquer 100 100 >> dividecon_out
./test divideconquer 100 100 >> dividecon_out
./test divideconquer 100 100 >> dividecon_out
echo "jarvis"
./test jarvis 100 100 >> jarvis_out
./test jarvis 100 100 >> jarvis_out
./test jarvis 100 100 >> jarvis_out
./test jarvis 100 100 >> jarvis_out
./test jarvis 100 100 >> jarvis_out
./test jarvis 100 100 >> jarvis_out
./test jarvis 100 100 >> jarvis_out
echo "graham"
./test graham 100 100 >> graham_out
./test graham 100 100 >> graham_out
./test graham 100 100 >> graham_out
./test graham 100 100 >> graham_out
./test graham 100 100 >> graham_out
./test graham 100 100 >> graham_out
./test graham 100 100 >> graham_out
echo -e
echo -e
echo "	testing using 1000 random points within square bounding box"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 1000 1000 >> newalgo_out
./test newalgo 1000 1000 >> newalgo_out
./test newalgo 1000 1000 >> newalgo_out
./test newalgo 1000 1000 >> newalgo_out
./test newalgo 1000 1000 >> newalgo_out
./test newalgo 1000 1000 >> newalgo_out
./test newalgo 1000 1000 >> newalgo_out
echo "divideconquer"
./test divideconquer 1000 1000 >> dividecon_out
./test divideconquer 1000 1000 >> dividecon_out
./test divideconquer 1000 1000 >> dividecon_out
./test divideconquer 1000 1000 >> dividecon_out
./test divideconquer 1000 1000 >> dividecon_out
./test divideconquer 1000 1000 >> dividecon_out
./test divideconquer 1000 1000 >> dividecon_out
echo "jarvis"
./test jarvis 1000 1000 >> jarvis_out
./test jarvis 1000 1000 >> jarvis_out
./test jarvis 1000 1000 >> jarvis_out
./test jarvis 1000 1000 >> jarvis_out
./test jarvis 1000 1000 >> jarvis_out
./test jarvis 1000 1000 >> jarvis_out
./test jarvis 1000 1000 >> jarvis_out
echo "graham"
./test graham 1000 1000 >> graham_out
./test graham 1000 1000 >> graham_out
./test graham 1000 1000 >> graham_out
./test graham 1000 1000 >> graham_out
./test graham 1000 1000 >> graham_out
./test graham 1000 1000 >> graham_out
./test graham 1000 1000 >> graham_out
echo -e
echo -e
echo "	testing using 10000 random points within square bounding box"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 10000 10000 >> newalgo_out
./test newalgo 10000 10000 >> newalgo_out
./test newalgo 10000 10000 >> newalgo_out
./test newalgo 10000 10000 >> newalgo_out
./test newalgo 10000 10000 >> newalgo_out
./test newalgo 10000 10000 >> newalgo_out
./test newalgo 10000 10000 >> newalgo_out
echo "divideconquer"
./test divideconquer 10000 10000 >> dividecon_out
./test divideconquer 10000 10000 >> dividecon_out
./test divideconquer 10000 10000 >> dividecon_out
./test divideconquer 10000 10000 >> dividecon_out
./test divideconquer 10000 10000 >> dividecon_out
./test divideconquer 10000 10000 >> dividecon_out
./test divideconquer 10000 10000 >> dividecon_out
echo "jarvis"
./test jarvis 10000 10000 >> jarvis_out
./test jarvis 10000 10000 >> jarvis_out
./test jarvis 10000 10000 >> jarvis_out
./test jarvis 10000 10000 >> jarvis_out
./test jarvis 10000 10000 >> jarvis_out
./test jarvis 10000 10000 >> jarvis_out
./test jarvis 10000 10000 >> jarvis_out
echo "graham"
./test graham 10000 10000 >> graham_out
./test graham 10000 10000 >> graham_out
./test graham 10000 10000 >> graham_out
./test graham 10000 10000 >> graham_out
./test graham 10000 10000 >> graham_out
./test graham 10000 10000 >> graham_out
./test graham 10000 10000 >> graham_out
echo -e
echo -e
echo "	testing using 100000 random points within square bounding box"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 100000 1000 >> newalgo_out
./test newalgo 100000 1000 >> newalgo_out
./test newalgo 100000 1000 >> newalgo_out
./test newalgo 100000 1000 >> newalgo_out
./test newalgo 100000 1000 >> newalgo_out
./test newalgo 100000 1000 >> newalgo_out
./test newalgo 100000 1000 >> newalgo_out
echo "divideconquer"
./test divideconquer 100000 1000 >> dividecon_out
./test divideconquer 100000 1000 >> dividecon_out
./test divideconquer 100000 1000 >> dividecon_out
./test divideconquer 100000 1000 >> dividecon_out
./test divideconquer 100000 1000 >> dividecon_out
./test divideconquer 100000 1000 >> dividecon_out
./test divideconquer 100000 1000 >> dividecon_out
echo "jarvis"
./test jarvis 100000 1000 >> jarvis_out
./test jarvis 100000 1000 >> jarvis_out
./test jarvis 100000 1000 >> jarvis_out
./test jarvis 100000 1000 >> jarvis_out
./test jarvis 100000 1000 >> jarvis_out
./test jarvis 100000 1000 >> jarvis_out
./test jarvis 100000 1000 >> jarvis_out
echo "graham"
./test graham 100000 1000 >> graham_out
./test graham 100000 1000 >> graham_out
./test graham 100000 1000 >> graham_out
./test graham 100000 1000 >> graham_out
./test graham 100000 1000 >> graham_out
./test graham 100000 1000 >> graham_out
./test graham 100000 1000 >> graham_out


















echo -e
echo -e
echo "	testing using 10 random points within circle bounding box"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 10 10 -c >> newalgo_out
./test newalgo 10 10 -c >> newalgo_out
./test newalgo 10 10 -c >> newalgo_out
./test newalgo 10 10 -c >> newalgo_out
./test newalgo 10 10 -c >> newalgo_out
./test newalgo 10 10 -c >> newalgo_out
./test newalgo 10 10 -c >> newalgo_out
echo "divideconquer"
./test divideconquer 10 10 -c >> dividecon_out
./test divideconquer 10 10 -c >> dividecon_out
./test divideconquer 10 10 -c >> dividecon_out
./test divideconquer 10 10 -c >> dividecon_out
./test divideconquer 10 10 -c >> dividecon_out
./test divideconquer 10 10 -c >> dividecon_out
./test divideconquer 10 10 -c >> dividecon_out
echo "jarvis"
./test jarvis 10 10 -c >> jarvis_out
./test jarvis 10 10 -c >> jarvis_out
./test jarvis 10 10 -c >> jarvis_out
./test jarvis 10 10 -c >> jarvis_out
./test jarvis 10 10 -c >> jarvis_out
./test jarvis 10 10 -c >> jarvis_out
./test jarvis 10 10 -c >> jarvis_out
echo "graham"
./test graham 10 10 -c >> graham_out
./test graham 10 10 -c >> graham_out
./test graham 10 10 -c >> graham_out
./test graham 10 10 -c >> graham_out
./test graham 10 10 -c >> graham_out
./test graham 10 10 -c >> graham_out
./test graham 10 10 -c >> graham_out
echo -e
echo -e
echo "	testing using 100 random points within circle bounding box"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 100 100 -c >> newalgo_out
./test newalgo 100 100 -c >> newalgo_out
./test newalgo 100 100 -c >> newalgo_out
./test newalgo 100 100 -c >> newalgo_out
./test newalgo 100 100 -c >> newalgo_out
./test newalgo 100 100 -c >> newalgo_out
./test newalgo 100 100 -c >> newalgo_out
echo "divideconquer"
./test divideconquer 100 100 -c >> dividecon_out
./test divideconquer 100 100 -c >> dividecon_out
./test divideconquer 100 100 -c >> dividecon_out
./test divideconquer 100 100 -c >> dividecon_out
./test divideconquer 100 100 -c >> dividecon_out
./test divideconquer 100 100 -c >> dividecon_out
./test divideconquer 100 100 -c >> dividecon_out
echo "jarvis"
./test jarvis 100 100 -c >> jarvis_out
./test jarvis 100 100 -c >> jarvis_out
./test jarvis 100 100 -c >> jarvis_out
./test jarvis 100 100 -c >> jarvis_out
./test jarvis 100 100 -c >> jarvis_out
./test jarvis 100 100 -c >> jarvis_out
./test jarvis 100 100 -c >> jarvis_out
echo "graham"
./test graham 100 100 -c >> graham_out
./test graham 100 100 -c >> graham_out
./test graham 100 100 -c >> graham_out
./test graham 100 100 -c >> graham_out
./test graham 100 100 -c >> graham_out
./test graham 100 100 -c >> graham_out
./test graham 100 100 -c >> graham_out
echo -e
echo -e
echo "	testing using 1000 random points within circle bounding box"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 1000 1000 -c >> newalgo_out
./test newalgo 1000 1000 -c >> newalgo_out
./test newalgo 1000 1000 -c >> newalgo_out
./test newalgo 1000 1000 -c >> newalgo_out
./test newalgo 1000 1000 -c >> newalgo_out
./test newalgo 1000 1000 -c >> newalgo_out
./test newalgo 1000 1000 -c >> newalgo_out
echo "divideconquer"
./test divideconquer 1000 1000 -c >> dividecon_out
./test divideconquer 1000 1000 -c >> dividecon_out
./test divideconquer 1000 1000 -c >> dividecon_out
./test divideconquer 1000 1000 -c >> dividecon_out
./test divideconquer 1000 1000 -c >> dividecon_out
./test divideconquer 1000 1000 -c >> dividecon_out
./test divideconquer 1000 1000 -c >> dividecon_out
echo "jarvis"
./test jarvis 1000 1000 -c >> jarvis_out
./test jarvis 1000 1000 -c >> jarvis_out
./test jarvis 1000 1000 -c >> jarvis_out
./test jarvis 1000 1000 -c >> jarvis_out
./test jarvis 1000 1000 -c >> jarvis_out
./test jarvis 1000 1000 -c >> jarvis_out
./test jarvis 1000 1000 -c >> jarvis_out
echo "graham"
./test graham 1000 1000 -c >> graham_out
./test graham 1000 1000 -c >> graham_out
./test graham 1000 1000 -c >> graham_out
./test graham 1000 1000 -c >> graham_out
./test graham 1000 1000 -c >> graham_out
./test graham 1000 1000 -c >> graham_out
./test graham 1000 1000 -c >> graham_out
echo -e
echo -e
echo "	testing using 10000 random points within circle bounding box"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 10000 10000 -c >> newalgo_out
./test newalgo 10000 10000 -c >> newalgo_out
./test newalgo 10000 10000 -c >> newalgo_out
./test newalgo 10000 10000 -c >> newalgo_out
./test newalgo 10000 10000 -c >> newalgo_out
./test newalgo 10000 10000 -c >> newalgo_out
./test newalgo 10000 10000 -c >> newalgo_out
echo "divideconquer"
./test divideconquer 10000 10000 -c >> dividecon_out
./test divideconquer 10000 10000 -c >> dividecon_out
./test divideconquer 10000 10000 -c >> dividecon_out
./test divideconquer 10000 10000 -c >> dividecon_out
./test divideconquer 10000 10000 -c >> dividecon_out
./test divideconquer 10000 10000 -c >> dividecon_out
./test divideconquer 10000 10000 -c >> dividecon_out
echo "jarvis"
./test jarvis 10000 10000 -c >> jarvis_out
./test jarvis 10000 10000 -c >> jarvis_out
./test jarvis 10000 10000 -c >> jarvis_out
./test jarvis 10000 10000 -c >> jarvis_out
./test jarvis 10000 10000 -c >> jarvis_out
./test jarvis 10000 10000 -c >> jarvis_out
./test jarvis 10000 10000 -c >> jarvis_out
echo "graham"
./test graham 10000 10000 -c >> graham_out
./test graham 10000 10000 -c >> graham_out
./test graham 10000 10000 -c >> graham_out
./test graham 10000 10000 -c >> graham_out
./test graham 10000 10000 -c >> graham_out
./test graham 10000 10000 -c >> graham_out
./test graham 10000 10000 -c >> graham_out
echo -e
echo -e
echo "	testing using 100000 random points within circle bounding box"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 100000 1000 -c >> newalgo_out
./test newalgo 100000 1000 -c >> newalgo_out
./test newalgo 100000 1000 -c >> newalgo_out
./test newalgo 100000 1000 -c >> newalgo_out
./test newalgo 100000 1000 -c >> newalgo_out
./test newalgo 100000 1000 -c >> newalgo_out
./test newalgo 100000 1000 -c >> newalgo_out
echo "divideconquer"
./test divideconquer 100000 1000 -c >> dividecon_out
./test divideconquer 100000 1000 -c >> dividecon_out
./test divideconquer 100000 1000 -c >> dividecon_out
./test divideconquer 100000 1000 -c >> dividecon_out
./test divideconquer 100000 1000 -c >> dividecon_out
./test divideconquer 100000 1000 -c >> dividecon_out
./test divideconquer 100000 1000 -c >> dividecon_out
echo "jarvis"
./test jarvis 100000 1000 -c >> jarvis_out
./test jarvis 100000 1000 -c >> jarvis_out
./test jarvis 100000 1000 -c >> jarvis_out
./test jarvis 100000 1000 -c >> jarvis_out
./test jarvis 100000 1000 -c >> jarvis_out
./test jarvis 100000 1000 -c >> jarvis_out
./test jarvis 100000 1000 -c >> jarvis_out
echo "graham"
./test graham 100000 1000 -c >> graham_out
./test graham 100000 1000 -c >> graham_out
./test graham 100000 1000 -c >> graham_out
./test graham 100000 1000 -c >> graham_out
./test graham 100000 1000 -c >> graham_out
./test graham 100000 1000 -c >> graham_out
./test graham 100000 1000 -c >> graham_out



























echo -e
echo -e
echo "	testing using 10 random points close to circle edge"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 10 10 -c -c >> newalgo_out
./test newalgo 10 10 -c -c >> newalgo_out
./test newalgo 10 10 -c -c >> newalgo_out
./test newalgo 10 10 -c -c >> newalgo_out
./test newalgo 10 10 -c -c >> newalgo_out
./test newalgo 10 10 -c -c >> newalgo_out
./test newalgo 10 10 -c -c >> newalgo_out
echo "divideconquer"
./test divideconquer 10 10 -c -c >> dividecon_out
./test divideconquer 10 10 -c -c >> dividecon_out
./test divideconquer 10 10 -c -c >> dividecon_out
./test divideconquer 10 10 -c -c >> dividecon_out
./test divideconquer 10 10 -c -c >> dividecon_out
./test divideconquer 10 10 -c -c >> dividecon_out
./test divideconquer 10 10 -c -c >> dividecon_out
echo "jarvis"
./test jarvis 10 10 -c -c >> jarvis_out
./test jarvis 10 10 -c -c >> jarvis_out
./test jarvis 10 10 -c -c >> jarvis_out
./test jarvis 10 10 -c -c >> jarvis_out
./test jarvis 10 10 -c -c >> jarvis_out
./test jarvis 10 10 -c -c >> jarvis_out
./test jarvis 10 10 -c -c >> jarvis_out
echo "graham"
./test graham 10 10 -c -c >> graham_out
./test graham 10 10 -c -c >> graham_out
./test graham 10 10 -c -c >> graham_out
./test graham 10 10 -c -c >> graham_out
./test graham 10 10 -c -c >> graham_out
./test graham 10 10 -c -c >> graham_out
./test graham 10 10 -c -c >> graham_out
echo -e
echo -e
echo "	testing using 100 random points close to circle edge"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 100 100 -c -c >> newalgo_out
./test newalgo 100 100 -c -c >> newalgo_out
./test newalgo 100 100 -c -c >> newalgo_out
./test newalgo 100 100 -c -c >> newalgo_out
./test newalgo 100 100 -c -c >> newalgo_out
./test newalgo 100 100 -c -c >> newalgo_out
./test newalgo 100 100 -c -c >> newalgo_out
echo "divideconquer"
./test divideconquer 100 100 -c -c >> dividecon_out
./test divideconquer 100 100 -c -c >> dividecon_out
./test divideconquer 100 100 -c -c >> dividecon_out
./test divideconquer 100 100 -c -c >> dividecon_out
./test divideconquer 100 100 -c -c >> dividecon_out
./test divideconquer 100 100 -c -c >> dividecon_out
./test divideconquer 100 100 -c -c >> dividecon_out
echo "jarvis"
./test jarvis 100 100 -c -c >> jarvis_out
./test jarvis 100 100 -c -c >> jarvis_out
./test jarvis 100 100 -c -c >> jarvis_out
./test jarvis 100 100 -c -c >> jarvis_out
./test jarvis 100 100 -c -c >> jarvis_out
./test jarvis 100 100 -c -c >> jarvis_out
./test jarvis 100 100 -c -c >> jarvis_out
echo "graham"
./test graham 100 100 -c -c >> graham_out
./test graham 100 100 -c -c >> graham_out
./test graham 100 100 -c -c >> graham_out
./test graham 100 100 -c -c >> graham_out
./test graham 100 100 -c -c >> graham_out
./test graham 100 100 -c -c >> graham_out
./test graham 100 100 -c -c >> graham_out
echo -e
echo -e
echo "	testing using 1000 random points close to circle edge"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 1000 1000 -c -c >> newalgo_out
./test newalgo 1000 1000 -c -c >> newalgo_out
./test newalgo 1000 1000 -c -c >> newalgo_out
./test newalgo 1000 1000 -c -c >> newalgo_out
./test newalgo 1000 1000 -c -c >> newalgo_out
./test newalgo 1000 1000 -c -c >> newalgo_out
./test newalgo 1000 1000 -c -c >> newalgo_out
echo "divideconquer"
./test divideconquer 1000 1000 -c -c >> dividecon_out
./test divideconquer 1000 1000 -c -c >> dividecon_out
./test divideconquer 1000 1000 -c -c >> dividecon_out
./test divideconquer 1000 1000 -c -c >> dividecon_out
./test divideconquer 1000 1000 -c -c >> dividecon_out
./test divideconquer 1000 1000 -c -c >> dividecon_out
./test divideconquer 1000 1000 -c -c >> dividecon_out
echo "jarvis"
./test jarvis 1000 1000 -c -c >> jarvis_out
./test jarvis 1000 1000 -c -c >> jarvis_out
./test jarvis 1000 1000 -c -c >> jarvis_out
./test jarvis 1000 1000 -c -c >> jarvis_out
./test jarvis 1000 1000 -c -c >> jarvis_out
./test jarvis 1000 1000 -c -c >> jarvis_out
./test jarvis 1000 1000 -c -c >> jarvis_out
echo "graham"
./test graham 1000 1000 -c -c >> graham_out
./test graham 1000 1000 -c -c >> graham_out
./test graham 1000 1000 -c -c >> graham_out
./test graham 1000 1000 -c -c >> graham_out
./test graham 1000 1000 -c -c >> graham_out
./test graham 1000 1000 -c -c >> graham_out
./test graham 1000 1000 -c -c >> graham_out
echo -e
echo -e
echo "	testing using 10000 random points close to circle edge"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 10000 10000 -c -c >> newalgo_out
./test newalgo 10000 10000 -c -c >> newalgo_out
./test newalgo 10000 10000 -c -c >> newalgo_out
./test newalgo 10000 10000 -c -c >> newalgo_out
./test newalgo 10000 10000 -c -c >> newalgo_out
./test newalgo 10000 10000 -c -c >> newalgo_out
./test newalgo 10000 10000 -c -c >> newalgo_out
echo "divideconquer"
./test divideconquer 10000 10000 -c -c >> dividecon_out
./test divideconquer 10000 10000 -c -c >> dividecon_out
./test divideconquer 10000 10000 -c -c >> dividecon_out
./test divideconquer 10000 10000 -c -c >> dividecon_out
./test divideconquer 10000 10000 -c -c >> dividecon_out
./test divideconquer 10000 10000 -c -c >> dividecon_out
./test divideconquer 10000 10000 -c -c >> dividecon_out
echo "jarvis"
./test jarvis 10000 10000 -c -c >> jarvis_out
./test jarvis 10000 10000 -c -c >> jarvis_out
./test jarvis 10000 10000 -c -c >> jarvis_out
./test jarvis 10000 10000 -c -c >> jarvis_out
./test jarvis 10000 10000 -c -c >> jarvis_out
./test jarvis 10000 10000 -c -c >> jarvis_out
./test jarvis 10000 10000 -c -c >> jarvis_out
echo "graham"
./test graham 10000 10000 -c -c >> graham_out
./test graham 10000 10000 -c -c >> graham_out
./test graham 10000 10000 -c -c >> graham_out
./test graham 10000 10000 -c -c >> graham_out
./test graham 10000 10000 -c -c >> graham_out
./test graham 10000 10000 -c -c >> graham_out
./test graham 10000 10000 -c -c >> graham_out
echo -e
echo -e
echo "	testing using 100000 random points close to circle edge"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 100000 1000 -c -c >> newalgo_out
./test newalgo 100000 1000 -c -c >> newalgo_out
./test newalgo 100000 1000 -c -c >> newalgo_out
./test newalgo 100000 1000 -c -c >> newalgo_out
./test newalgo 100000 1000 -c -c >> newalgo_out
./test newalgo 100000 1000 -c -c >> newalgo_out
./test newalgo 100000 1000 -c -c >> newalgo_out
echo "divideconquer"
./test divideconquer 100000 1000 -c -c >> dividecon_out
./test divideconquer 100000 1000 -c -c >> dividecon_out
./test divideconquer 100000 1000 -c -c >> dividecon_out
./test divideconquer 100000 1000 -c -c >> dividecon_out
./test divideconquer 100000 1000 -c -c >> dividecon_out
./test divideconquer 100000 1000 -c -c >> dividecon_out
./test divideconquer 100000 1000 -c -c >> dividecon_out
echo "jarvis"
./test jarvis 100000 1000 -c -c >> jarvis_out
./test jarvis 100000 1000 -c -c >> jarvis_out
./test jarvis 100000 1000 -c -c >> jarvis_out
./test jarvis 100000 1000 -c -c >> jarvis_out
./test jarvis 100000 1000 -c -c >> jarvis_out
./test jarvis 100000 1000 -c -c >> jarvis_out
./test jarvis 100000 1000 -c -c >> jarvis_out
echo "graham"
./test graham 100000 1000 -c -c >> graham_out
./test graham 100000 1000 -c -c >> graham_out
./test graham 100000 1000 -c -c >> graham_out
./test graham 100000 1000 -c -c >> graham_out
./test graham 100000 1000 -c -c >> graham_out
./test graham 100000 1000 -c -c >> graham_out
./test graham 100000 1000 -c -c >> graham_out


















echo -e
echo -e
echo "	testing using 10 random points on circle edge"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 10 10 -c -e >> newalgo_out
./test newalgo 10 10 -c -e >> newalgo_out
./test newalgo 10 10 -c -e >> newalgo_out
./test newalgo 10 10 -c -e >> newalgo_out
./test newalgo 10 10 -c -e >> newalgo_out
./test newalgo 10 10 -c -e >> newalgo_out
./test newalgo 10 10 -c -e >> newalgo_out
echo "divideconquer"
./test divideconquer 10 10 -c -e >> dividecon_out
./test divideconquer 10 10 -c -e >> dividecon_out
./test divideconquer 10 10 -c -e >> dividecon_out
./test divideconquer 10 10 -c -e >> dividecon_out
./test divideconquer 10 10 -c -e >> dividecon_out
./test divideconquer 10 10 -c -e >> dividecon_out
./test divideconquer 10 10 -c -e >> dividecon_out
echo "jarvis"
./test jarvis 10 10 -c -e >> jarvis_out
./test jarvis 10 10 -c -e >> jarvis_out
./test jarvis 10 10 -c -e >> jarvis_out
./test jarvis 10 10 -c -e >> jarvis_out
./test jarvis 10 10 -c -e >> jarvis_out
./test jarvis 10 10 -c -e >> jarvis_out
./test jarvis 10 10 -c -e >> jarvis_out
echo "graham"
./test graham 10 10 -c -e >> graham_out
./test graham 10 10 -c -e >> graham_out
./test graham 10 10 -c -e >> graham_out
./test graham 10 10 -c -e >> graham_out
./test graham 10 10 -c -e >> graham_out
./test graham 10 10 -c -e >> graham_out
./test graham 10 10 -c -e >> graham_out
echo -e
echo -e
echo "	testing using 100 random points on circle edge"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 100 100 -c -e >> newalgo_out
./test newalgo 100 100 -c -e >> newalgo_out
./test newalgo 100 100 -c -e >> newalgo_out
./test newalgo 100 100 -c -e >> newalgo_out
./test newalgo 100 100 -c -e >> newalgo_out
./test newalgo 100 100 -c -e >> newalgo_out
./test newalgo 100 100 -c -e >> newalgo_out
echo "divideconquer"
./test divideconquer 100 100 -c -e >> dividecon_out
./test divideconquer 100 100 -c -e >> dividecon_out
./test divideconquer 100 100 -c -e >> dividecon_out
./test divideconquer 100 100 -c -e >> dividecon_out
./test divideconquer 100 100 -c -e >> dividecon_out
./test divideconquer 100 100 -c -e >> dividecon_out
./test divideconquer 100 100 -c -e >> dividecon_out
echo "jarvis"
./test jarvis 100 100 -c -e >> jarvis_out
./test jarvis 100 100 -c -e >> jarvis_out
./test jarvis 100 100 -c -e >> jarvis_out
./test jarvis 100 100 -c -e >> jarvis_out
./test jarvis 100 100 -c -e >> jarvis_out
./test jarvis 100 100 -c -e >> jarvis_out
./test jarvis 100 100 -c -e >> jarvis_out
echo "graham"
./test graham 100 100 -c -e >> graham_out
./test graham 100 100 -c -e >> graham_out
./test graham 100 100 -c -e >> graham_out
./test graham 100 100 -c -e >> graham_out
./test graham 100 100 -c -e >> graham_out
./test graham 100 100 -c -e >> graham_out
./test graham 100 100 -c -e >> graham_out
echo -e
echo -e
echo "	testing using 1000 random points on circle edge"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 1000 1000 -c -e >> newalgo_out
./test newalgo 1000 1000 -c -e >> newalgo_out
./test newalgo 1000 1000 -c -e >> newalgo_out
./test newalgo 1000 1000 -c -e >> newalgo_out
./test newalgo 1000 1000 -c -e >> newalgo_out
./test newalgo 1000 1000 -c -e >> newalgo_out
./test newalgo 1000 1000 -c -e >> newalgo_out
echo "divideconquer"
./test divideconquer 1000 1000 -c -e >> dividecon_out
./test divideconquer 1000 1000 -c -e >> dividecon_out
./test divideconquer 1000 1000 -c -e >> dividecon_out
./test divideconquer 1000 1000 -c -e >> dividecon_out
./test divideconquer 1000 1000 -c -e >> dividecon_out
./test divideconquer 1000 1000 -c -e >> dividecon_out
./test divideconquer 1000 1000 -c -e >> dividecon_out
echo "jarvis"
./test jarvis 1000 1000 -c -e >> jarvis_out
./test jarvis 1000 1000 -c -e >> jarvis_out
./test jarvis 1000 1000 -c -e >> jarvis_out
./test jarvis 1000 1000 -c -e >> jarvis_out
./test jarvis 1000 1000 -c -e >> jarvis_out
./test jarvis 1000 1000 -c -e >> jarvis_out
./test jarvis 1000 1000 -c -e >> jarvis_out
echo "graham"
./test graham 1000 1000 -c -e >> graham_out
./test graham 1000 1000 -c -e >> graham_out
./test graham 1000 1000 -c -e >> graham_out
./test graham 1000 1000 -c -e >> graham_out
./test graham 1000 1000 -c -e >> graham_out
./test graham 1000 1000 -c -e >> graham_out
./test graham 1000 1000 -c -e >> graham_out
echo -e
echo -e
echo "	testing using 10000 random points on circle edge"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 10000 10000 -c -e >> newalgo_out
./test newalgo 10000 10000 -c -e >> newalgo_out
./test newalgo 10000 10000 -c -e >> newalgo_out
./test newalgo 10000 10000 -c -e >> newalgo_out
./test newalgo 10000 10000 -c -e >> newalgo_out
./test newalgo 10000 10000 -c -e >> newalgo_out
./test newalgo 10000 10000 -c -e >> newalgo_out
echo "divideconquer"
./test divideconquer 10000 10000 -c -e >> dividecon_out
./test divideconquer 10000 10000 -c -e >> dividecon_out
./test divideconquer 10000 10000 -c -e >> dividecon_out
./test divideconquer 10000 10000 -c -e >> dividecon_out
./test divideconquer 10000 10000 -c -e >> dividecon_out
./test divideconquer 10000 10000 -c -e >> dividecon_out
./test divideconquer 10000 10000 -c -e >> dividecon_out
echo "jarvis"
./test jarvis 10000 10000 -c -e >> jarvis_out
./test jarvis 10000 10000 -c -e >> jarvis_out
./test jarvis 10000 10000 -c -e >> jarvis_out
./test jarvis 10000 10000 -c -e >> jarvis_out
./test jarvis 10000 10000 -c -e >> jarvis_out
./test jarvis 10000 10000 -c -e >> jarvis_out
./test jarvis 10000 10000 -c -e >> jarvis_out
echo "graham"
./test graham 10000 10000 -c -e >> graham_out
./test graham 10000 10000 -c -e >> graham_out
./test graham 10000 10000 -c -e >> graham_out
./test graham 10000 10000 -c -e >> graham_out
./test graham 10000 10000 -c -e >> graham_out
./test graham 10000 10000 -c -e >> graham_out
./test graham 10000 10000 -c -e >> graham_out
echo -e
echo -e
echo "	testing using 100000 random points on circle edge"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 100000 1000 -c -e >> newalgo_out
./test newalgo 100000 1000 -c -e >> newalgo_out
./test newalgo 100000 1000 -c -e >> newalgo_out
./test newalgo 100000 1000 -c -e >> newalgo_out
./test newalgo 100000 1000 -c -e >> newalgo_out
./test newalgo 100000 1000 -c -e >> newalgo_out
./test newalgo 100000 1000 -c -e >> newalgo_out
echo "divideconquer"
./test divideconquer 100000 1000 -c -e >> dividecon_out
./test divideconquer 100000 1000 -c -e >> dividecon_out
./test divideconquer 100000 1000 -c -e >> dividecon_out
./test divideconquer 100000 1000 -c -e >> dividecon_out
./test divideconquer 100000 1000 -c -e >> dividecon_out
./test divideconquer 100000 1000 -c -e >> dividecon_out
./test divideconquer 100000 1000 -c -e >> dividecon_out
echo "jarvis"
./test jarvis 100000 1000 -c -e >> jarvis_out
./test jarvis 100000 1000 -c -e >> jarvis_out
./test jarvis 100000 1000 -c -e >> jarvis_out
./test jarvis 100000 1000 -c -e >> jarvis_out
./test jarvis 100000 1000 -c -e >> jarvis_out
./test jarvis 100000 1000 -c -e >> jarvis_out
./test jarvis 100000 1000 -c -e >> jarvis_out
echo "graham"
./test graham 100000 1000 -c -e >> graham_out
./test graham 100000 1000 -c -e >> graham_out
./test graham 100000 1000 -c -e >> graham_out
./test graham 100000 1000 -c -e >> graham_out
./test graham 100000 1000 -c -e >> graham_out
./test graham 100000 1000 -c -e >> graham_out
./test graham 100000 1000 -c -e >> graham_out




























echo -e
echo -e
echo "	testing using 10 random points on square edge"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 10 10 -s -e >> newalgo_out
./test newalgo 10 10 -s -e >> newalgo_out
./test newalgo 10 10 -s -e >> newalgo_out
./test newalgo 10 10 -s -e >> newalgo_out
./test newalgo 10 10 -s -e >> newalgo_out
./test newalgo 10 10 -s -e >> newalgo_out
./test newalgo 10 10 -s -e >> newalgo_out
echo "divideconquer"
./test divideconquer 10 10 -s -e >> dividecon_out
./test divideconquer 10 10 -s -e >> dividecon_out
./test divideconquer 10 10 -s -e >> dividecon_out
./test divideconquer 10 10 -s -e >> dividecon_out
./test divideconquer 10 10 -s -e >> dividecon_out
./test divideconquer 10 10 -s -e >> dividecon_out
./test divideconquer 10 10 -s -e >> dividecon_out
echo "jarvis"
./test jarvis 10 10 -s -e >> jarvis_out
./test jarvis 10 10 -s -e >> jarvis_out
./test jarvis 10 10 -s -e >> jarvis_out
./test jarvis 10 10 -s -e >> jarvis_out
./test jarvis 10 10 -s -e >> jarvis_out
./test jarvis 10 10 -s -e >> jarvis_out
./test jarvis 10 10 -s -e >> jarvis_out
echo "graham"
./test graham 10 10 -s -e >> graham_out
./test graham 10 10 -s -e >> graham_out
./test graham 10 10 -s -e >> graham_out
./test graham 10 10 -s -e >> graham_out
./test graham 10 10 -s -e >> graham_out
./test graham 10 10 -s -e >> graham_out
./test graham 10 10 -s -e >> graham_out
echo -e
echo -e
echo "	testing using 100 random points on square edge"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 100 100 -s -e >> newalgo_out
./test newalgo 100 100 -s -e >> newalgo_out
./test newalgo 100 100 -s -e >> newalgo_out
./test newalgo 100 100 -s -e >> newalgo_out
./test newalgo 100 100 -s -e >> newalgo_out
./test newalgo 100 100 -s -e >> newalgo_out
./test newalgo 100 100 -s -e >> newalgo_out
echo "divideconquer"
./test divideconquer 100 100 -s -e >> dividecon_out
./test divideconquer 100 100 -s -e >> dividecon_out
./test divideconquer 100 100 -s -e >> dividecon_out
./test divideconquer 100 100 -s -e >> dividecon_out
./test divideconquer 100 100 -s -e >> dividecon_out
./test divideconquer 100 100 -s -e >> dividecon_out
./test divideconquer 100 100 -s -e >> dividecon_out
echo "jarvis"
./test jarvis 100 100 -s -e >> jarvis_out
./test jarvis 100 100 -s -e >> jarvis_out
./test jarvis 100 100 -s -e >> jarvis_out
./test jarvis 100 100 -s -e >> jarvis_out
./test jarvis 100 100 -s -e >> jarvis_out
./test jarvis 100 100 -s -e >> jarvis_out
./test jarvis 100 100 -s -e >> jarvis_out
echo "graham"
./test graham 100 100 -s -e >> graham_out
./test graham 100 100 -s -e >> graham_out
./test graham 100 100 -s -e >> graham_out
./test graham 100 100 -s -e >> graham_out
./test graham 100 100 -s -e >> graham_out
./test graham 100 100 -s -e >> graham_out
./test graham 100 100 -s -e >> graham_out
echo -e
echo -e
echo "	testing using 1000 random points on square edge"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 1000 1000 -s -e >> newalgo_out
./test newalgo 1000 1000 -s -e >> newalgo_out
./test newalgo 1000 1000 -s -e >> newalgo_out
./test newalgo 1000 1000 -s -e >> newalgo_out
./test newalgo 1000 1000 -s -e >> newalgo_out
./test newalgo 1000 1000 -s -e >> newalgo_out
./test newalgo 1000 1000 -s -e >> newalgo_out
echo "divideconquer"
./test divideconquer 1000 1000 -s -e >> dividecon_out
./test divideconquer 1000 1000 -s -e >> dividecon_out
./test divideconquer 1000 1000 -s -e >> dividecon_out
./test divideconquer 1000 1000 -s -e >> dividecon_out
./test divideconquer 1000 1000 -s -e >> dividecon_out
./test divideconquer 1000 1000 -s -e >> dividecon_out
./test divideconquer 1000 1000 -s -e >> dividecon_out
echo "jarvis"
./test jarvis 1000 1000 -s -e >> jarvis_out
./test jarvis 1000 1000 -s -e >> jarvis_out
./test jarvis 1000 1000 -s -e >> jarvis_out
./test jarvis 1000 1000 -s -e >> jarvis_out
./test jarvis 1000 1000 -s -e >> jarvis_out
./test jarvis 1000 1000 -s -e >> jarvis_out
./test jarvis 1000 1000 -s -e >> jarvis_out
echo "graham"
./test graham 1000 1000 -s -e >> graham_out
./test graham 1000 1000 -s -e >> graham_out
./test graham 1000 1000 -s -e >> graham_out
./test graham 1000 1000 -s -e >> graham_out
./test graham 1000 1000 -s -e >> graham_out
./test graham 1000 1000 -s -e >> graham_out
./test graham 1000 1000 -s -e >> graham_out
echo -e
echo -e
echo "	testing using 10000 random points on square edge"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 10000 10000 -s -e >> newalgo_out
./test newalgo 10000 10000 -s -e >> newalgo_out
./test newalgo 10000 10000 -s -e >> newalgo_out
./test newalgo 10000 10000 -s -e >> newalgo_out
./test newalgo 10000 10000 -s -e >> newalgo_out
./test newalgo 10000 10000 -s -e >> newalgo_out
./test newalgo 10000 10000 -s -e >> newalgo_out
echo "divideconquer"
./test divideconquer 10000 10000 -s -e >> dividecon_out
./test divideconquer 10000 10000 -s -e >> dividecon_out
./test divideconquer 10000 10000 -s -e >> dividecon_out
./test divideconquer 10000 10000 -s -e >> dividecon_out
./test divideconquer 10000 10000 -s -e >> dividecon_out
./test divideconquer 10000 10000 -s -e >> dividecon_out
./test divideconquer 10000 10000 -s -e >> dividecon_out
echo "jarvis"
./test jarvis 10000 10000 -s -e >> jarvis_out
./test jarvis 10000 10000 -s -e >> jarvis_out
./test jarvis 10000 10000 -s -e >> jarvis_out
./test jarvis 10000 10000 -s -e >> jarvis_out
./test jarvis 10000 10000 -s -e >> jarvis_out
./test jarvis 10000 10000 -s -e >> jarvis_out
./test jarvis 10000 10000 -s -e >> jarvis_out
echo "graham"
./test graham 10000 10000 -s -e >> graham_out
./test graham 10000 10000 -s -e >> graham_out
./test graham 10000 10000 -s -e >> graham_out
./test graham 10000 10000 -s -e >> graham_out
./test graham 10000 10000 -s -e >> graham_out
./test graham 10000 10000 -s -e >> graham_out
./test graham 10000 10000 -s -e >> graham_out
echo -e
echo -e
echo "	testing using 100000 random points on square edge"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 100000 1000 -s -e >> newalgo_out
./test newalgo 100000 1000 -s -e >> newalgo_out
./test newalgo 100000 1000 -s -e >> newalgo_out
./test newalgo 100000 1000 -s -e >> newalgo_out
./test newalgo 100000 1000 -s -e >> newalgo_out
./test newalgo 100000 1000 -s -e >> newalgo_out
./test newalgo 100000 1000 -s -e >> newalgo_out
echo "divideconquer"
./test divideconquer 100000 1000 -s -e >> dividecon_out
./test divideconquer 100000 1000 -s -e >> dividecon_out
./test divideconquer 100000 1000 -s -e >> dividecon_out
./test divideconquer 100000 1000 -s -e >> dividecon_out
./test divideconquer 100000 1000 -s -e >> dividecon_out
./test divideconquer 100000 1000 -s -e >> dividecon_out
./test divideconquer 100000 1000 -s -e >> dividecon_out
echo "jarvis"
./test jarvis 100000 1000 -s -e >> jarvis_out
./test jarvis 100000 1000 -s -e >> jarvis_out
./test jarvis 100000 1000 -s -e >> jarvis_out
./test jarvis 100000 1000 -s -e >> jarvis_out
./test jarvis 100000 1000 -s -e >> jarvis_out
./test jarvis 100000 1000 -s -e >> jarvis_out
./test jarvis 100000 1000 -s -e >> jarvis_out
echo "graham"
./test graham 100000 1000 -s -e >> graham_out
./test graham 100000 1000 -s -e >> graham_out
./test graham 100000 1000 -s -e >> graham_out
./test graham 100000 1000 -s -e >> graham_out
./test graham 100000 1000 -s -e >> graham_out
./test graham 100000 1000 -s -e >> graham_out
./test graham 100000 1000 -s -e >> graham_out












echo -e
echo -e
echo "	testing using 10 random points close to square edge"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 10 10 -s -c >> newalgo_out
./test newalgo 10 10 -s -c >> newalgo_out
./test newalgo 10 10 -s -c >> newalgo_out
./test newalgo 10 10 -s -c >> newalgo_out
./test newalgo 10 10 -s -c >> newalgo_out
./test newalgo 10 10 -s -c >> newalgo_out
./test newalgo 10 10 -s -c >> newalgo_out
echo "divideconquer"
./test divideconquer 10 10 -s -c >> dividecon_out
./test divideconquer 10 10 -s -c >> dividecon_out
./test divideconquer 10 10 -s -c >> dividecon_out
./test divideconquer 10 10 -s -c >> dividecon_out
./test divideconquer 10 10 -s -c >> dividecon_out
./test divideconquer 10 10 -s -c >> dividecon_out
./test divideconquer 10 10 -s -c >> dividecon_out
echo "jarvis"
./test jarvis 10 10 -s -c >> jarvis_out
./test jarvis 10 10 -s -c >> jarvis_out
./test jarvis 10 10 -s -c >> jarvis_out
./test jarvis 10 10 -s -c >> jarvis_out
./test jarvis 10 10 -s -c >> jarvis_out
./test jarvis 10 10 -s -c >> jarvis_out
./test jarvis 10 10 -s -c >> jarvis_out
echo "graham"
./test graham 10 10 -s -c >> graham_out
./test graham 10 10 -s -c >> graham_out
./test graham 10 10 -s -c >> graham_out
./test graham 10 10 -s -c >> graham_out
./test graham 10 10 -s -c >> graham_out
./test graham 10 10 -s -c >> graham_out
./test graham 10 10 -s -c >> graham_out
echo -e
echo -e
echo "	testing using 100 random points close to square edge"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 100 100 -s -c >> newalgo_out
./test newalgo 100 100 -s -c >> newalgo_out
./test newalgo 100 100 -s -c >> newalgo_out
./test newalgo 100 100 -s -c >> newalgo_out
./test newalgo 100 100 -s -c >> newalgo_out
./test newalgo 100 100 -s -c >> newalgo_out
./test newalgo 100 100 -s -c >> newalgo_out
echo "divideconquer"
./test divideconquer 100 100 -s -c >> dividecon_out
./test divideconquer 100 100 -s -c >> dividecon_out
./test divideconquer 100 100 -s -c >> dividecon_out
./test divideconquer 100 100 -s -c >> dividecon_out
./test divideconquer 100 100 -s -c >> dividecon_out
./test divideconquer 100 100 -s -c >> dividecon_out
./test divideconquer 100 100 -s -c >> dividecon_out
echo "jarvis"
./test jarvis 100 100 -s -c >> jarvis_out
./test jarvis 100 100 -s -c >> jarvis_out
./test jarvis 100 100 -s -c >> jarvis_out
./test jarvis 100 100 -s -c >> jarvis_out
./test jarvis 100 100 -s -c >> jarvis_out
./test jarvis 100 100 -s -c >> jarvis_out
./test jarvis 100 100 -s -c >> jarvis_out
echo "graham"
./test graham 100 100 -s -c >> graham_out
./test graham 100 100 -s -c >> graham_out
./test graham 100 100 -s -c >> graham_out
./test graham 100 100 -s -c >> graham_out
./test graham 100 100 -s -c >> graham_out
./test graham 100 100 -s -c >> graham_out
./test graham 100 100 -s -c >> graham_out
echo -e
echo -e
echo "	testing using 1000 random points close to square edge"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 1000 1000 -s -c >> newalgo_out
./test newalgo 1000 1000 -s -c >> newalgo_out
./test newalgo 1000 1000 -s -c >> newalgo_out
./test newalgo 1000 1000 -s -c >> newalgo_out
./test newalgo 1000 1000 -s -c >> newalgo_out
./test newalgo 1000 1000 -s -c >> newalgo_out
./test newalgo 1000 1000 -s -c >> newalgo_out
echo "divideconquer"
./test divideconquer 1000 1000 -s -c >> dividecon_out
./test divideconquer 1000 1000 -s -c >> dividecon_out
./test divideconquer 1000 1000 -s -c >> dividecon_out
./test divideconquer 1000 1000 -s -c >> dividecon_out
./test divideconquer 1000 1000 -s -c >> dividecon_out
./test divideconquer 1000 1000 -s -c >> dividecon_out
./test divideconquer 1000 1000 -s -c >> dividecon_out
echo "jarvis"
./test jarvis 1000 1000 -s -c >> jarvis_out
./test jarvis 1000 1000 -s -c >> jarvis_out
./test jarvis 1000 1000 -s -c >> jarvis_out
./test jarvis 1000 1000 -s -c >> jarvis_out
./test jarvis 1000 1000 -s -c >> jarvis_out
./test jarvis 1000 1000 -s -c >> jarvis_out
./test jarvis 1000 1000 -s -c >> jarvis_out
echo "graham"
./test graham 1000 1000 -s -c >> graham_out
./test graham 1000 1000 -s -c >> graham_out
./test graham 1000 1000 -s -c >> graham_out
./test graham 1000 1000 -s -c >> graham_out
./test graham 1000 1000 -s -c >> graham_out
./test graham 1000 1000 -s -c >> graham_out
./test graham 1000 1000 -s -c >> graham_out
echo -e
echo -e
echo "	testing using 10000 random points close to square edge"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 10000 10000 -s -c >> newalgo_out
./test newalgo 10000 10000 -s -c >> newalgo_out
./test newalgo 10000 10000 -s -c >> newalgo_out
./test newalgo 10000 10000 -s -c >> newalgo_out
./test newalgo 10000 10000 -s -c >> newalgo_out
./test newalgo 10000 10000 -s -c >> newalgo_out
./test newalgo 10000 10000 -s -c >> newalgo_out
echo "divideconquer"
./test divideconquer 10000 10000 -s -c >> dividecon_out
./test divideconquer 10000 10000 -s -c >> dividecon_out
./test divideconquer 10000 10000 -s -c >> dividecon_out
./test divideconquer 10000 10000 -s -c >> dividecon_out
./test divideconquer 10000 10000 -s -c >> dividecon_out
./test divideconquer 10000 10000 -s -c >> dividecon_out
./test divideconquer 10000 10000 -s -c >> dividecon_out
echo "jarvis"
./test jarvis 10000 10000 -s -c >> jarvis_out
./test jarvis 10000 10000 -s -c >> jarvis_out
./test jarvis 10000 10000 -s -c >> jarvis_out
./test jarvis 10000 10000 -s -c >> jarvis_out
./test jarvis 10000 10000 -s -c >> jarvis_out
./test jarvis 10000 10000 -s -c >> jarvis_out
./test jarvis 10000 10000 -s -c >> jarvis_out
echo "graham"
./test graham 10000 10000 -s -c >> graham_out
./test graham 10000 10000 -s -c >> graham_out
./test graham 10000 10000 -s -c >> graham_out
./test graham 10000 10000 -s -c >> graham_out
./test graham 10000 10000 -s -c >> graham_out
./test graham 10000 10000 -s -c >> graham_out
./test graham 10000 10000 -s -c >> graham_out
echo -e
echo -e
echo "	testing using 100000 random points close to square edge"
echo "========================================================================="
echo -e >> newalgo_out
echo -e >> dividecon_out
echo -e >> jarvis_out
echo -e >> graham_out
echo "newalgo"
./test newalgo 100000 1000 -s -c >> newalgo_out
./test newalgo 100000 1000 -s -c >> newalgo_out
./test newalgo 100000 1000 -s -c >> newalgo_out
./test newalgo 100000 1000 -s -c >> newalgo_out
./test newalgo 100000 1000 -s -c >> newalgo_out
./test newalgo 100000 1000 -s -c >> newalgo_out
./test newalgo 100000 1000 -s -c >> newalgo_out
echo "divideconquer"
./test divideconquer 100000 1000 -s -c >> dividecon_out
./test divideconquer 100000 1000 -s -c >> dividecon_out
./test divideconquer 100000 1000 -s -c >> dividecon_out
./test divideconquer 100000 1000 -s -c >> dividecon_out
./test divideconquer 100000 1000 -s -c >> dividecon_out
./test divideconquer 100000 1000 -s -c >> dividecon_out
./test divideconquer 100000 1000 -s -c >> dividecon_out
echo "jarvis"
./test jarvis 100000 1000 -s -c >> jarvis_out
./test jarvis 100000 1000 -s -c >> jarvis_out
./test jarvis 100000 1000 -s -c >> jarvis_out
./test jarvis 100000 1000 -s -c >> jarvis_out
./test jarvis 100000 1000 -s -c >> jarvis_out
./test jarvis 100000 1000 -s -c >> jarvis_out
./test jarvis 100000 1000 -s -c >> jarvis_out
echo "graham"
./test graham 100000 1000 -s -c >> graham_out
./test graham 100000 1000 -s -c >> graham_out
./test graham 100000 1000 -s -c >> graham_out
./test graham 100000 1000 -s -c >> graham_out
./test graham 100000 1000 -s -c >> graham_out
./test graham 100000 1000 -s -c >> graham_out
./test graham 100000 1000 -s -c >> graham_out