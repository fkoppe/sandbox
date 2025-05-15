verbose=''

while test $# -gt 0; do
           case "$1" in
                -v)
                    shift
                    verbose="--verbose"
                    shift
                    ;;
                *)
                   echo "$1 is not a recognized flag"
                   exit 1;
                   ;;
          esac
  done

cd ./build_cli
ctest --output-on-failure ${verbose} .
