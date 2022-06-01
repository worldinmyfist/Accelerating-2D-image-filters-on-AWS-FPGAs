# FPGA-project

## HOW TO RUN THE CODE
```bash
cd Filter
make TARGETS=hw DEVICES=$AWS_PLATFORM app
sudo sh
source /opt/xilinx/xrt/setup.sh
./Filter2D.exe -i img/picadilly.bmp -n 10 -x ./xclbin/fpga1k.hw.xilinx_aws-vu9p-f1-04261818_dynamic_5_0.awsxclbin
```
The application loads a 1080p image {picadilly.bmp here} (-i argument)
It processes this image 10 times (-n argument)
It uses a FPGA binary with 1 kernel (-x argument)
