#include "osgART/VideoConfig"


namespace osgART {

	/* converts character based fourcc to its numerical representation */
	unsigned int charToFourCC(const char* fourcc) 
	{
		return (fourcc[3] << 24) + (fourcc[2] << 16) + (fourcc[1] << 8 ) + fourcc[0];
	}

	VideoConfig::VideoConfig() : _id(0)
	{
	}

	/*virtual*/
	VideoConfig::~VideoConfig() 
	{
	}

		//	VIDEOFORMAT_RGB555 = 0,
		//VIDEOFORMAT_RGB565,
		//VIDEOFORMAT_RGB24,		// GL_RGB, GL_UNSIGNED_BYTE
		//VIDEOFORMAT_BGR24,		// GL_BGR, GL_UNSIGNED_BYTE
		//VIDEOFORMAT_RGBA32,		// GL_RGBA, GL_UNSIGNED_BYTE
		//VIDEOFORMAT_BGRA32,		// GL_BGRA, GL_UNSIGNED_BYTE (Win 32 native)
		//VIDEOFORMAT_ARGB32,		// GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV (BE) or GL_UNSIGNED_INT_8_8_8_8 (LE) (Mac OS native)
		//VIDEOFORMAT_ABGR32,		// GL_ABGR_EXT, GL_UNSIGNED_BYTE (SGI native)
		//VIDEOFORMAT_Y8,			// GL_LUMINANCE, GL_UNSIGNED_BYTE
		//VIDEOFORMAT_Y16,		// GL_LUMINANCE, GL_UNSIGNED_SHORT
		//VIDEOFORMAT_YUV444,
		//VIDEOFORMAT_YUV422,
		//VIDEOFORMAT_YUV422P,
		//VIDEOFORMAT_YUV411,
		//VIDEOFORMAT_YUV411P,
		//VIDEOFORMAT_YUV420P,
		//VIDEOFORMAT_YUV410P,
		//VIDEOFORMAT_GREY8,		// GL_LUMINANCE, GL_UNSIGNED_BYTE
		//VIDEOFORMAT_MJPEG,
		//VIDEOFORMAT_422YpCbCr8,	// GL_YCBCR_422_APPLE/GL_YCBCR_MESA, GL_UNSIGNED_SHORT_8_8_REV_APPLE/GL_UNSIGNED_SHORT_8_8_REV_MESA (BE) or GL_UNSIGNED_SHORT_8_8_APPLE/GL_UNSIGNED_SHORT_8_8_MESA (LE) (Mac OS '2vuy').
		//VIDEOFORMAT_422YpCbCr8R,// GL_YCBCR_422_APPLE/GL_YCBCR_MESA, GL_UNSIGNED_SHORT_8_8_APPLE/GL_UNSIGNED_SHORT_8_8_MESA (BE) or GL_UNSIGNED_SHORT_8_8_REV_APPLE/GL_UNSIGNED_SHORT_8_8_REV_MESA (LE) (Mac OS 'yuvs').
		//VIDEOFORMAT_ANY 


	void VideoConfig::setPixelFormat(const std::string& fourcc)
	{
		unsigned int fourcc_num = charToFourCC(fourcc.c_str());

		switch (fourcc_num)
		{

			/* Y800 */
			case 0x30303859 :
			/* Y8 */
			case 0x20203859 :
				_pixelformat = VIDEOFORMAT_Y8;
				break;
			/* Y16 */
			case 0x20363159 :
				_pixelformat = VIDEOFORMAT_Y16;
				break;

			/* IYU2 */
			case 0x32555949 :
                _pixelformat = VIDEOFORMAT_YUV444;
				break;

			/* Y422 */
			case 0x32323459:
			/* UYVY */
			case 0x59565955:
				_pixelformat = VIDEOFORMAT_YUV422;
				break;

			/* \TODO : implement the rest of the FourCC */

		}

	}

	/*virtual*/ 
	void 
	VideoConfig::showDeviceDialog()
	{}

	/*virtual*/ 
	void 
	VideoConfig::showFormatDialog()
	{}

}