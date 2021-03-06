

#include <cv.h>

#include <cxcore.h>

#include <highgui.h>

#include <cmath>



using namespace std;

using namespace cv;



int main(int argc, char ** argv)

{

	IplImage *scr = 0;

	IplImage *dst = 0;

	double scale = 4;

	CvSize dst_cvsize;

	if (argc == 2 && (scr = cvLoadImage(argv[1], -1)) != 0)

	{

		dst_cvsize.width = (int)(scr->width*scale);

		dst_cvsize.height = (int)(scr->height*scale);

		dst = cvCreateImage(dst_cvsize, scr->depth, scr->nChannels);



		cvResize(scr, dst, CV_INTER_NN);//

										//             CV_INTER_NN - 最近邻插值,

										//             CV_INTER_LINEAR - 双线性插值 (缺省使用)

										//             CV_INTER_AREA - 使用象素关系重采样。当图像缩小时候，该方法可以避免波纹出现。

										/*当图像放大时，类似于 CV_INTER_NN 方法..*/

										//             CV_INTER_CUBIC - 立方插值.



		cvNamedWindow("scr", CV_WINDOW_AUTOSIZE);

		cvNamedWindow("dst", CV_WINDOW_AUTOSIZE);

		cvShowImage("scr", scr);

		cvShowImage("dst", dst);

		cvWaitKey();

		cvReleaseImage(&scr);

		cvReleaseImage(&dst);

		cvDestroyWindow("scr");

		cvDestroyWindow("dst");

	}

	return 0;

}