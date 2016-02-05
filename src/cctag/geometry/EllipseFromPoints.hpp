#ifndef _CCTAG_NUMERICAL_ELLIPSEFROMPOINTS_HPP_
#define _CCTAG_NUMERICAL_ELLIPSEFROMPOINTS_HPP_

#include <cctag/geometry/Ellipse.hpp>
#include <cctag/algebra/matrix/Matrix.hpp>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/types_c.h>

#include <boost/foreach.hpp>
#include <boost/math/constants/constants.hpp>

#include <cstddef>
#include <cmath>
#include <vector>


namespace cctag {
namespace numerical {
namespace geometry {

Point2dN<double> extractEllipsePointAtAngle( const Ellipse & ellipse, double theta );
///@todo rename this function
void points( const Ellipse & ellipse, const std::size_t nb, std::vector< cctag::Point2dN<double> > & pts );
///@todo rename this function
void points( const Ellipse & ellipse, const std::size_t nb, const double phi1, const double phi2, std::vector< cctag::Point2dN<double> > & pts );

template <class T>
void fitEllipse( const std::vector<cctag::Point2dN< T > > & points, Ellipse& e )
{
	std::vector<cv::Point2f> cvpts;
	cvpts.reserve( points.size() );
	BOOST_FOREACH( const cctag::Point2dN< T > & pt, points )
	{
		cvpts.push_back( cv::Point2f( float(pt.x()), float(pt.y()) ) );
	}

	const cv::RotatedRect rR = cv::fitEllipse( cv::Mat( cvpts ) );
	const double xC           = rR.center.x;
	const double yC           = rR.center.y;

	const double b = rR.size.height / 2.0;
	const double a = rR.size.width / 2.0;

	const double angle = rR.angle * boost::math::constants::pi<double>() / 180.0;

	//CCTAG_TCOUT_VAR(points[0]);
	//CCTAG_TCOUT_VAR(xC);
	//CCTAG_TCOUT_VAR(yC);
	//CCTAG_TCOUT_VAR(a);
	//CCTAG_TCOUT_VAR(b);
	//CCTAG_TCOUT_VAR(angle);

	e.setParameters( Point2dN<double>( xC, yC ), a, b, angle );

	//CCTAG_TCOUT_VAR(boost::numeric::ublas::inner_prod(points[0],bounded_vector<double,3>(boost::numeric::ublas::prec_prod(e.matrix(),points[0]))));

	//cvWaitKey(0);
}

void ellipsePoint( const cctag::numerical::geometry::Ellipse& ellipse, double theta, cctag::numerical::BoundedVector3d& pt );


void computeIntermediatePoints(const Ellipse & ellipse, Point2dN<int> & pt11, Point2dN<int> & pt12, Point2dN<int> & pt21, Point2dN<int> & pt22);
void rasterizeEllipticalArc(const Ellipse & ellipse, const Point2dN<int> & pt1, const Point2dN<int> & pt2, std::vector< Point2dN<int> > & vPoint, std::size_t intersectionIndex);
void rasterizeEllipse( const Ellipse & ellipse, std::vector< Point2dN<int> > & vPoint );

/**
 * Get the pixel perimeter of an ellipse
 * @param ellipse
 * @return the perimeter in number of pixels
 */
std::size_t rasterizeEllipsePerimeter( const Ellipse & ellipse );

/**
 * @brief Compute intersections if there, between a line of equation Y = y and an ellipse.
 *
 * @param[in] ellipse
 * @param[in] y ordonate for which we compute x values of intersections
 * @return intersected points sorted in ascend order (returns x coordinates: 0, 1, or 2 points).
 */
std::vector<double> intersectEllipseWithLine( const numerical::geometry::Ellipse& ellipse, const double y, bool horizontal);

}
}
}

#endif
