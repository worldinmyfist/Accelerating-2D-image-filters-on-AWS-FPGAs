# Accelerating 2D image filters on AWS FPGAs

## HOW TO RUN THE CODE
```bash
cd Filter
make TARGETS=hw DEVICES=$AWS_PLATFORM app
sudo sh
source /opt/xilinx/xrt/setup.sh
./Filter2D.exe -i img/picadilly.bmp -n 10 -x ./xclbin/fpga1k.hw.xilinx_aws-vu9p-f1-04261818_dynamic_5_0.awsxclbin
```
The command loads a 1080p image {picadilly.bmp here} (-i argument). Change this according to the input image. <br/>
It processes this image 10 times (-n argument). Change this according to requirement. <br/>
It uses a FPGA binary with 1 kernel (-x argument). To use the binary with 3 kernels, use [./xclbin/fpga3k.hw.xilinx_aws-vu9p-f1-04261818_dynamic_5_0.awsxclbin](https://github.com/worldinmyfist/FPGA-project/blob/main/Filter/xclbin/fpga3k.hw.xilinx_aws-vu9p-f1-04261818_dynamic_5_0.awsxclbin). To use the binary with 6 kernels, use [./xclbin/fpga6k.hw.xilinx_aws-vu9p-f1-04261818_dynamic_5_0.awsxclbin](https://github.com/worldinmyfist/FPGA-project/blob/main/Filter/xclbin/fpga6k.hw.xilinx_aws-vu9p-f1-04261818_dynamic_5_0.awsxclbin). <br/>

## NOTE
* Make sure you are on AWS platform and have access to AWS FPGAs. 
* Pre-compiled binaries are being used here. They can be created as well by following this [link](https://github.com/awslabs/aws-fpga-app-notes/blob/master/reInvent18_Developer_Workshop/FILTER2D_Lab.md#building-the-fpga-binary-to-execute-on-f1).

## AUTHOR
[ARYAN AGARWAL](https://github.com/worldinmyfist/)

## CONTRIBUTION
Pull requests are welcome. For major changes, please open an issue to discuss what you would like to change.
