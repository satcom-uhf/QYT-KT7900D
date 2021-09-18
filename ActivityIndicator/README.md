# Activity indicator ([RU](README.md))

It's just a LED indicates squelch state. Just use signal from pin 2 and invert it:

![rj45](rj45.jpg)

![not](Not.jpg)

![diagram](Diagram.png)

## Components

- NPN transistor (i.e. 2222)
- 3 resistors 1k
- LED

## Step 1

Unmount PTT front panel and drill a hole for LED

![PrepareFrontPanel](PrepareFrontPanel.jpg)

## Step 2

Look for a hidden cut wire from the second pin of RJ45

![hidden](HiddenWire.jpg)

## Step 3

Make it longer

![LongerWire](MakeItLonger.jpg)

## Step 4

Mount components

![components](MountComponents.jpg)

![done](Done.jpg)

## Step 5

Enable REP-M mode and test it:

No activity

![No Activity](NoActivity.jpg)

Someone on the air

![Activity](Activity.jpg)
