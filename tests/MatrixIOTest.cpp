#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"

using namespace Eigen;

struct MatrixIOFixture {
  MatrixIOFixture()
  {
    expectedM3 = MatrixXd(3, 3);
    expectedM3 << 0.680375, 0.59688, -0.329554,
        -0.211234, 0.823295, 0.536459,
        0.566198, -0.604897, -0.444451;
  }

  MatrixXd    expectedM3;
  std::string pathM3   = "../data/m3.csv";
  std::string pathM10  = "../data/m10.csv";
  std::string pathM50  = "../data/m50.csv";
  std::string pathM250 = "../data/m250.csv";
};

BOOST_FIXTURE_TEST_SUITE(MatrixIOTests, MatrixIOFixture, *boost::unit_test::tolerance(1e-12))

BOOST_AUTO_TEST_CASE(LoadM3Matrix)
{
  int      expectedRows = expectedM3.rows();
  int      expectedCols = expectedM3.cols();
  MatrixXd M3           = matrixIO::openData(this->pathM3, expectedRows);

  // Check dimensions
  BOOST_TEST(M3.rows() == expectedRows);
  BOOST_TEST(M3.cols() == expectedCols);

  for (int i = 0; i < M3.rows(); i++) {
    for (int j = 0; j < M3.cols(); j++) {
      BOOST_TEST(M3(i, j) == expectedM3(i, j));
    }
  }
}

BOOST_AUTO_TEST_CASE(LoadM10Matrix)
{
  int      expectedRows = 10;
  int      expectedCols = 10;
  MatrixXd M10          = matrixIO::openData(this->pathM10, expectedRows);

  // Check dimensions
  BOOST_TEST(M10.rows() == expectedRows);
  BOOST_TEST(M10.cols() == expectedCols);
}

BOOST_AUTO_TEST_CASE(LoadM50Matrix)
{
  int      expectedRows = 50;
  int      expectedCols = 50;
  MatrixXd M50          = matrixIO::openData(this->pathM50, expectedRows);

  // Check dimensions
  BOOST_TEST(M50.rows() == expectedRows);
  BOOST_TEST(M50.cols() == expectedCols);
}

BOOST_AUTO_TEST_CASE(LoadM250Matrix)
{
  int      expectedRows = 250;
  int      expectedCols = 250;
  MatrixXd M250         = matrixIO::openData(this->pathM250, expectedRows);

  // Check dimensions
  BOOST_TEST(M250.rows() == expectedRows);
  BOOST_TEST(M250.cols() == expectedCols);
}

BOOST_AUTO_TEST_SUITE_END()
