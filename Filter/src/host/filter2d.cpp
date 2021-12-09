
#include "filter2d.h"
#include "window2d.h"
int maxi = 0;

void Filter2D(
        const    short coeffs[FILTER2D_KERNEL_V_SIZE][FILTER2D_KERNEL_H_SIZE],
		unsigned char *srcImg,
		unsigned int   width,
		unsigned int   height,
		unsigned int   stride,
		unsigned char *dstImg )
{

	Window2D<FILTER2D_KERNEL_H_SIZE, FILTER2D_KERNEL_V_SIZE, unsigned char> pixelWindow1(width, height, stride);

    if(coeffs[0][0]==0)
	{
		maxi = 0;
		for(int y=0; y<height; ++y)
		{
			for(int x=0; x<width; ++x)
			{
				// Add a new pixel to the linebuffer, generate a new pixel window
				pixelWindow1.next(srcImg, x, y);

				// Apply 2D filter to the pixel window
				int sum = 0;
				for(int row=0; row<FILTER2D_KERNEL_V_SIZE; row++)
				{
					for(int col=0; col<FILTER2D_KERNEL_H_SIZE; col++)
					{
						sum += pixelWindow1(row,col)*coeffs[row][col];
					}
				}
				
				if(sum>=0 && (float)(sum-maxi)>0.01f)
				{
					maxi = (int)(sum+1);
				}
				else if(sum<0 && (float)((-1*sum)-maxi)>0.01f)
				{
					maxi = (int)((-1*sum)+1);
				}
			}
		}
	}

	Window2D<FILTER2D_KERNEL_H_SIZE, FILTER2D_KERNEL_V_SIZE, unsigned char> pixelWindow(width, height, stride);

	for(int y=0; y<height; ++y)
    {
        for(int x=0; x<width; ++x)
        {
        	// Add a new pixel to the linebuffer, generate a new pixel window
			pixelWindow.next(srcImg, x, y);

        	// Apply 2D filter to the pixel window
			int sum = 0;
			for(int row=0; row<FILTER2D_KERNEL_V_SIZE; row++)
			{
				for(int col=0; col<FILTER2D_KERNEL_H_SIZE; col++)
				{
					sum += pixelWindow(row,col)*coeffs[row][col];
				}
			}
			
			unsigned char outpix;

			// Normalize result
			outpix = (unsigned char)(sum/(FILTER2D_KERNEL_V_SIZE*FILTER2D_KERNEL_H_SIZE));

			// Write output
           	dstImg[y*stride+x] = outpix;
        }
    }
}



