//get funds from users
// withdraw funds
// set a minimum funding value in usd
// SPDX-License-Identifier: MIT
pragma solidity ^0.8.8;

import "./PriceConverter.sol";

error NotOwner();

/**@title A sample Funding Contract
 * @author uday
 * @notice This contract is for creating a sample funding contract
 * @dev This implements price feeds as our library
 */

contract FundMe {
    using PriceConverter for uint256;

    //state variables
    uint256 public constant MINIMUM_USD = 50 * 1e18; // matching values with conversion and getprice
    address[] public funders; // keep track of all funds we get
    mapping(address => uint256) public addressToAmountFunded;
    address public immutable i_owner;
    AggregatorV3Interface public priceFeed;

    //events (we have none)

    //modifiers
    modifier onlyOwner() {
        // _; putting above does the execution of function and check the condition after that
        //require(msg.sender == i_owner, "sender is not owner");
        if (msg.sender != i_owner) {
            revert NotOwner();
        }
        _; // putting _ here checks for condition first then only executes the function
    }

    // Functions Order:
    //// constructor
    //// receive
    //// fallback
    //// external
    //// public
    //// internal
    //// private
    //// view / pure

    constructor(address priceFeedAddress) {
        i_owner = msg.sender;
        priceFeed = AggregatorV3Interface(priceFeedAddress);
    }

    /// @notice Funds our contract based on the ETH/USD price
    function fund() public payable {
        // want to be able to set a min fund amt in usd
        //1. how do we send eth to this contract?
        require(
            msg.value.getConversionRate(priceFeed) >= MINIMUM_USD,
            "didnt send enough"
        ); //=1eth in wei
        // 18 decimal places
        //above message reverts the error if occured
        //what is reverting?
        //undo any action before, and send remaining gas
        funders.push(msg.sender); //adds address(public address) of funders to the array
        addressToAmountFunded[msg.sender] += msg.value;
    }

    function withdraw() public onlyOwner {
        // require(msg.sender == owner, "sender is not owner");

        /* starting index, ending index, step amount */
        for (
            uint256 funderIndex = 0;
            funderIndex < funders.length;
            funderIndex++
        ) {
            address funder = funders[funderIndex];
            addressToAmountFunded[funder] = 0;
        }
        //reset the array
        funders = new address[](0);
        // actually withdraw the funds

        // //transfer
        // //msg.sender = address
        // // payable(msg.sender) = payable address
        // payable(msg.sender).transfer(address(this).balance);

        // //send
        // bool sendSuccess = payable(msg.sender).send(address(thus).balance);
        // require(sendSuccess, "send failed");

        // //call
        (bool callSuccess, ) = payable(msg.sender).call{
            value: address(this).balance
        }("");
        require(callSuccess, "call failed");
    }
}
