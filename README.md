# Quickfast

This is a custom version of the [QuickFast](https://github.com/objectcomputing/quickfast.git) implementation of the [FAST protocol](https://en.wikipedia.org/wiki/FAST_protocol).


## Clonning and Building

First, the repository must be cloned along with its submodules:

	git clone --recursive https://github.com/clearctvm/MarketData.Quickfast.git
	cd MarketData.Quickfast

It is necessary to set the Boost path for the Quickfast project. If there is a `BOOST_ROOT` environment variable set to the root of the Boost distribution, the file [`customBuildProperties.props.skel`](/solutions/customBuildProperties.props.skel), located under the `solutions` subdir, can be used as is:

    cd solutions
    copy customBuildProperties.props.skel customBuildProperties.props

Otherwise, copy (as above), edit the newly created `customBuildProperties.props` file and change the line:

		<BOOST_ROOT>$(BOOST_ROOT)</BOOST_ROOT>

into something like:

		<BOOST_ROOT>C:\path\to\boost</BOOST_ROOT>

Now, the solution `QuickFAST_VC140.sln` can be build. This can be achieved by opening the solution on Visual Studio 2015, selecting the proper values in the `Solution Configurations` and `Solution Platforms` drop lists and building the solution. Or equivalently from the command line:

	MSBuild QuickFAST_VC140.sln /p:Configuration="Static Debug" /p:Platform=x64 /m

The above command will build it in `Static Debug` for the `x64` platform.
