/*!
 *  \file       master-controller-tests.hpp
 *  \brief
 *
 */


#ifndef MASTER_CONTROLLER_TESTS_HPP
#define MASTER_CONTROLLER_TESTS_HPP

    #include <QtTest>

    #include <test_suite.hpp>
    #include <controllers/master_controller.hpp>

    namespace cm
    {
        namespace controllers
        {
            class MasterControllerTests : public TestSuite
            {
                Q_OBJECT
            public:
                MasterControllerTests();

            private slots:
                /*! \brief  Called before the first test function is executed */
                void initTestCase();
                /*! \brief  Called after the last test function was executed */
                void cleanupTestCase();
                /*! \brief  Called before each test function is executed */
                void init();
                /*! \brief  Called after each test function */
                void cleanup();

            private slots:
                void welcomeMessage_returnCorrectMessage();

            private:
                MasterController master_controller;
            };
        }
    }

#endif /* MASTER_CONTROLLER_TESTS_HPP */
