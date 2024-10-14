build_configuration="Debug"
test='False'

while test $# -gt 0; do
           case "$1" in
                -c)
                    shift
                    build_configuration=$1
                    shift
                    ;;
                -t)
                    shift
                    test="True"
                    shift
                    ;;
                *)
                   echo "$1 is not a recognized flag"
                   exit 1;
                   ;;
          esac
  done

cmake -B "./build" -G "Unix Makefiles" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=${build_configuration} -DDARK_TEST_ENABLE=${test} -DDEEP_TEST_ENABLE=${test}
